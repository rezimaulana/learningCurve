#include <fstream>
#include <iostream>
#define NMX 500005
#define fin cin
#define fout cout

using namespace std;

struct nod {
  long long a, b, d;
};
nod v[NMX];

long long s1[NMX], s2[NMX];
long long n, m1, m2, t;

int init() {
  // sg i%2

  s1[1] = (-v[1].b + 1 + v[1].a - 1);
  s2[1] = v[1].d + 1 - (-v[1].a + 1) + 1 + v[1].b - 1;

  long long x, y;

  for (int i = 2; i <= m1; i++) {
    x = s1[i - 1];
    y = s2[i - 1];

    x = x - v[i].a + 1;
    y = y - v[i].b + 1;

    s1[i] = y;
    s2[i] = v[i].d + 1 - x + 1;

    s1[i] += (v[i].a - 1);
    s2[i] += (v[i].b - 1);
  }

  return 0;
}

pair<long long, long long> cord(long long x) {
  std::pair<long long, long long> aux;

  aux.first = (x / n) + ((x % n) != 0);
  aux.second = (((x % n) == 0) * n) + (x % n);

  return aux;
}

int solve(pair<long long, long long> aux) {
  long long st, dr, mid, sol = -1;

  st = 1;
  dr = m1;

  while (st <= dr) {
    mid = (st + dr) >> 1;

    if (v[mid].a <= aux.first) {
      if (v[mid].a + v[mid].d < aux.first)
        dr = mid - 1;
      else {
        if (v[mid].b <= aux.second) {
          if (v[mid].b + v[mid].d < aux.second) {
            dr = mid - 1;
          } else
            sol = mid, st = mid + 1;
        } else
          dr = mid - 1;
      }
    } else
      dr = mid - 1;
  }

  return sol;
}

pair<long long, long long> verif(int pz, pair<long long, long long> aux) {
  int ps;

  if (pz & 1) {
    ps = (pz - 1) >> 1;

    if (ps & 1) {
      return make_pair(s1[pz] - aux.second, s2[pz] + aux.first);
    } else
      return make_pair(s1[pz] + aux.second, s2[pz] - aux.first);
  } else {
    ps = pz >> 1;

    if (ps & 1) {
      return make_pair(s1[pz] - aux.first, s2[pz] - aux.second);
    } else {
      return make_pair(s1[pz] + aux.first, s2[pz] + aux.second);
    }
  }

  return make_pair(0, 0);
}

int fnd(pair<long long, long long> aux) {
  int st, dr, mid, sol = -1;

  st = 1;
  dr = m1;

  pair<long long, long long> aux1;

  while (st <= dr) {
    mid = (st + dr) >> 1;

    aux1 = verif(mid, aux);

    if (v[mid].a <= aux1.first && aux1.first <= v[mid].a + v[mid].d &&
        v[mid].b <= aux1.second && aux1.second <= v[mid].b + v[mid].d) {
      st = mid + 1;
      sol = mid;
    } else
      dr = mid - 1;
  }

  return sol;
}

int main() {
  //   ifstream fin ("test.in");
  //   ofstream fout ("test.out");

  fin >> n;

  fin >> m1;

  for (int i = 1; i <= m1; i++) {
    fin >> v[i].a >> v[i].b >> v[i].d;
  }

  init();

  fin >> m2;

  std::pair<long long, long long> aux, aux1, aux2;

  int ps;

  while (m2--) {
    fin >> t;

    t++;

    aux = cord(t);

    int pz = fnd(aux);

    if (pz == -1) {
      fout << aux.first << " " << aux.second << "\n";

      continue;
    }

    aux1 = verif(pz, aux);

    fout << aux1.first << " " << aux1.second << "\n";
  }

  return 0;
}