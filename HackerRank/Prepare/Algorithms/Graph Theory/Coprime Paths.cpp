#include <bits/stdc++.h>

using namespace std;

const int N = 25123, LN = 15;
const int MaxVal = 10000000;

using ll = long long;

vector<int> adj[N];

int depth[N], parent[LN][N];
int ST[N], EN[N], cur_time = 0;
int vec[2 * N];

void dfs(int u = 0, int d = 0, int prev = -1) {
    depth[u] = d;
    parent[0][u] = prev;

    ST[u] = cur_time++;
    vec[ST[u]] = u;

    for (int v : adj[u]) {
        if (v == prev) continue;
        dfs(v, d + 1, u);
    }

    EN[u] = cur_time++;
    vec[EN[u]] = u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; i < LN; i++) {
        if ((diff >> i) & 1) {
            u = parent[i][u];
        }
    }

    if (u == v) return u;

    for (int i = LN - 1; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

vector<int> primes[N];
vector<pair<int, int>> upd[N];

int pr[MaxVal + 1], S;

ll ans[N];
bool used[N];

int vp[3][4 * N];

int main() {
    memset(parent, -1, sizeof parent);

    for (int i = 2; i <= MaxVal; i++) {
        if (!pr[i]) {
            for (int j = i + i; j <= MaxVal; j += i) {
                if (!pr[j]) pr[j] = i;
            }
        }
    }

    int n, q;
    scanf("%d %d", &n, &q);

    S = sqrt(2 * n);

    // printf("S = %d\n", S);

    map<int, int> p1;
    map<tuple<int, int>, int> p2;
    map<tuple<int, int, int>, int> p3;

    for (int i = 0; i < n; i++) {
        int id, x;
        scanf("%d", &x);

        auto& v = primes[i];

        while (pr[x]) {
            v.push_back(pr[x]);
            x /= pr[x];
        }

        if (x > 1) {
            v.push_back(x);
        }

        assert(is_sorted(begin(v), end(v)));
        v.resize(unique(begin(v), end(v)) - begin(v));

        for (int k = 0; k < v.size(); k++) {
            id = p1.size();
            if (p1.count(v[k])) id = p1[v[k]];
            else p1[v[k]] = id;

            upd[i].emplace_back(0, id);

            for (int j = k + 1; j < v.size(); j++) {
                auto tmp = make_tuple(v[k], v[j]);
                id = p2.size();
                if (p2.count(tmp)) id = p2[tmp];
                else p2[tmp] = id;

                upd[i].emplace_back(1, id);
            }
        }

        if (v.size() == 3) {
            auto tmp = make_tuple(v[0], v[1], v[2]);
            id = p3.size();
            if (p3.count(tmp)) id = p3[tmp];
            else p3[tmp] = id;

            upd[i].emplace_back(2, id);
        }
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    for (int i = 1; i < LN; i++) {
        for (int j = 0; j < n; j++) {
            if (parent[i - 1][j] != -1) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    using qt = tuple<int, int, int, int>;
    vector<qt> queries;
    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        if (ST[u] > ST[v]) swap(u, v);

        int p = lca(u, v);
        if (p == u) queries.emplace_back(ST[u], ST[v], i, -1);
        else {
            queries.emplace_back(EN[u], ST[v], i, p);
        }
    }

    sort(begin(queries), end(queries), [](const qt& a, const qt& b) -> bool {
        int l1, r1, i1, p1;
        int l2, r2, i2, p2;

        tie(l1, r1, i1, p1) = a;
        tie(l2, r2, i2, p2) = b;

        if (l1 / S != l2 / S) return l1 / S < l2 / S;
        return r1 > r2;
    });

    int active = 0;
    ll cur = 0;

    auto insert = [&](int u) {
        int tmp = active;

        for (auto& p : upd[u]) {
            if (p.first & 1) tmp += vp[p.first][p.second];
            else tmp -= vp[p.first][p.second];
        }

        cur += tmp;

        used[u] = true;
        active++;

        for (auto& p : upd[u]) {
            vp[p.first][p.second]++;
        }        
    };

    auto remove = [&](int u) {
        used[u] = false;
        active--;

        for (auto& p : upd[u]) {
            vp[p.first][p.second]--;
        }

        int tmp = active;

        for (auto& p : upd[u]) {
            if (p.first & 1) tmp += vp[p.first][p.second];
            else tmp -= vp[p.first][p.second];
        }

        cur -= tmp;        
    };

    int L = 0, R = -1;
    for (auto& t : queries) {
        int l, r, i, p;
        tie(l, r, i, p) = t;

        // printf("%d %d %d %d\n", l, r, i, p);

        while (R < r) {
            R++;
            if (used[vec[R]]) remove(vec[R]);
            else insert(vec[R]);
        }

        while (R > r) {
            if (used[vec[R]]) remove(vec[R]);
            else insert(vec[R]);
            R--;
        }

        while (L < l) {
            if (used[vec[L]]) remove(vec[L]);
            else insert(vec[L]);
            L++;
        }

        while (L > l) {
            L--;
            if (used[vec[L]]) remove(vec[L]);
            else insert(vec[L]);
        }

        ans[i] = cur;

        // printf("cur: %d\n", cur);

        if (p != -1) {
            int tmp = active;

            for (auto& k : upd[p]) {
                if (k.first & 1) tmp += vp[k.first][k.second];
                else tmp -= vp[k.first][k.second];
            }

            ans[i] += tmp;
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}