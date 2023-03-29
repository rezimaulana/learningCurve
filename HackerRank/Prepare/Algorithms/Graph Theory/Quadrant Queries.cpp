#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 100000;

const int R[4][4] =
{
  {0, 1, 2, 3},
  {3, 2, 1, 0},
  {1, 0, 3, 2},
  {2, 3, 0, 1}
};

int N;
int px[maxN], py[maxN];

int Q;

struct Node
{
  int l, r;
  int nq[4]; // number of points in each quadrant, applying reflect mask on children nodes (exclude self)
  int mask; // reflect mask X(0) Y(1)
  Node *lt, *rt;
};

Node *root;

Node *bst_build (int l, int r)
{
  Node *p = (Node *)malloc(sizeof(Node));
  p->l = l, p->r = r;
  memset(p->nq, 0, sizeof(p->nq));
  p->mask = 0;
  p->lt = p->rt = NULL;

  if (r - l > 1)
  {
    int m = (l + r) / 2;
    Node *lt = bst_build(l, m);
    Node *rt = bst_build(m, r);
    p->lt = lt;
    p->rt = rt;
  }

  if (r - l > 1)
  {
    for (int i = 0; i < 4; ++i)
      p->nq[i] = p->lt->nq[i] + p->rt->nq[i];
  }
  else
  {
    int q;
    if (px[l] > 0)
      if (py[l] > 0)
        q = 0;
      else
        q = 3;
    else
      if (py[l] > 0)
        q = 1;
      else
        q = 2;
    p->nq[q] = 1;
  }

  return p;
}

void bst_mask (int ax, Node *p, int l, int r)
{
  if (p->l == l && p->r == r)
  {
    p->mask ^= 1 << ax;
    return;
  }

  if (l < p->lt->r)
    bst_mask(ax, p->lt, l, min(r, p->lt->r));
  if (r > p->rt->l)
    bst_mask(ax, p->rt, max(l, p->rt->l), r);
  
  for (int i = 0; i < 4; ++i)
  {
    p->nq[i] = p->lt->nq[R[p->lt->mask][i]] + p->rt->nq[R[p->rt->mask][i]];
  }
}

void bst_query (Node *p, int l, int r, int mask, int res[4])
{
  mask ^= p->mask;
  
  if (p->l == l && p->r == r)
  {
    for (int i = 0; i < 4; ++i)
    {
      res[i] += p->nq[R[mask][i]];
    }
    return;
  }

  if (l < p->lt->r)
    bst_query(p->lt, l, min(r, p->lt->r), mask, res);
  if (r > p->rt->l)
    bst_query(p->rt, max(l, p->rt->l), r, mask, res);
}

int main ()
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
    scanf("%d%d", &px[i], &py[i]);

  root = bst_build(0, N);

  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i)
  {
    char c;
    int l, r;
    scanf(" %c%d%d", &c, &l, &r);
    --l;
    switch (c)
    {
      case 'X':
      {
        bst_mask(0, root, l, r);
        break;
      }
      case 'Y':
      {
        bst_mask(1, root, l, r);
        break;
      }
      case 'C':
      {
        int res[4];
        memset(res, 0, sizeof(res));
        bst_query(root, l, r, 0, res);
        printf("%d %d %d %d\n", res[0], res[1], res[2], res[3]);
        break;
      }
    }
  }
}