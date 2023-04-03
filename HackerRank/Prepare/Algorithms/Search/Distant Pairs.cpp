#include<complex>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

typedef complex<int> P;

bool SLT(const P&a, const P&b) {
    return real(a) < real(b) && imag(a) < imag(b);
}
bool LEBoth(const P &a, const P &b) {
    return a.real() <= b.real() && a.imag() <= b.imag();
}
bool byReal(const P &a, const P &b) {
    return a.real() < b.real();
}
bool byImag(const P &a, const P &b) {
    return a.imag() < b.imag();
}

struct Node {
    P p, ma, mi;
    Node *ch[2];
    Node(){}
    Node(const P&p_) : p(p_), ma(p_), mi(p_) {
    ch[0] = ch[1] = NULL;
    }
};

Node nodes[1000011];
int node_i;

struct Tree {
    template<class Iter> Node *build(Iter begin, Iter end, int d) {
    int len = end - begin;
    if (len == 0) return NULL;
    int c = len / 2;
    nth_element(begin, begin+c, end, (d? byImag: byReal));

    Node *x = &nodes[node_i++];
    *x = Node(*(begin + c));
    x->ch[0] = build(begin, begin + c, d ^ 1);
    x->ch[1] = build(begin+c+1, end, d ^ 1);

    REP (t, 2) if (x->ch[t] != NULL) {
        if (x->ch[t]) {
        x->mi.real(min(x->mi.real(), x->ch[t]->mi.real()));
        x->mi.imag(min(x->mi.imag(), x->ch[t]->mi.imag()));
        x->ma.real(max(x->ma.real(), x->ch[t]->ma.real()));
        x->ma.imag(max(x->ma.imag(), x->ch[t]->ma.imag()));
        }
    }
    return x;
    }

    bool find(const P &low, const P &high, int d, Node *x) {
    if (x == NULL) return false;

    if (LEBoth(low, x->p) && LEBoth(x->p, high)) return true;
    if (x->ma.real() < low.real() ||
        x->ma.imag() < low.imag() ||
        x->mi.real() > high.real() ||
        x->mi.imag() > high.imag()) return false;

    return find(low, high, d^1, x->ch[0]) ||
        find(low, high, d^1, x->ch[1]);
    }
};

int N, C;
int X[100111], Y[100111];

int main() {
    scanf("%d%d", &N, &C);
    REP (i, N) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    X[i] = x; Y[i] = y;
    }

    Tree tree;

    int lo = 0, hi = C / 4 + 1;
    while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    vector<P> ps;
    REP (i, N) if (Y[i] - X[i] >= mid && X[i]+C - Y[i] >= mid) {
        ps.emplace_back(X[i], Y[i]);
        ps.emplace_back(Y[i], X[i]+C);
    }

    bool yes = false;
    if (ps.size() <= 1u) {
        yes = false;
    } else {
        node_i = 0;
        tree.build(ps.begin(), ps.end(), 0);
        EACH (e, ps) {
        {
            P low(e->real() + mid, e->imag() + mid);
            P high(e->imag() - mid, e->real() + C - mid);
            if (LEBoth(low, high)) {
            bool tmp = tree.find(low, high, 0, &nodes[0]);
            if (tmp) {
                yes = true;
                break;
            }
            }
        }
        {
            P low(e->imag() + mid, e->imag() + mid);
            P high(e->real() + C - mid, e->real() + C - mid);
            if (LEBoth(low, high)) {
            bool tmp = tree.find(low, high, 0, &nodes[0]);
            if (tmp) {
                yes = true;
                break;
            }
            }
        }
        }
    }

    (yes? lo : hi) = mid;
    }

    printf("%d\n", lo);

    return 0;
}
