/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/07
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
struct edge {
  int to, nx;
} e[N * 2];
int n, q, r, ecnt, idc;
int head[N], dep[N], siz[N], son[N], top[N], f[N], st[N], en[N], id[N];
void add(int x, int y) {
  e[++ecnt].to = y;
  e[ecnt].nx = head[x];
  head[x] = ecnt;
}
void dfs1(int x) {
  siz[x] = 1;
  dep[x] = dep[f[x]] + 1;
  for (int i = head[x]; i; i = e[i].nx) {
    int nd = e[i].to;
    if (nd == f[x]) continue;
    f[nd] = x;
    dfs1(nd);
    siz[x] += siz[nd];
    if (!son[x] || siz[son[x]] < siz[nd]) son[x] = nd;
  }
}
void dfs2(int x, int tp) {
  id[x] = ++idc;
  st[x] = idc;
  top[x] = tp;
  if (son[x]) dfs2(son[x], tp);
  for (int i = head[x]; i; i = e[i].nx) {
    int nd = e[i].to;
    if (nd == f[x] || nd == son[x]) continue;
    dfs2(nd, nd);
  }
  en[x] = idc;
}
//使用条件 y 在 x的子树内
int lca2(int x, int y) {
  int t;
  while (top[x] != top[y]) t = top[y], y = f[top[y]];
  return x == y ? t : son[x];
}

/*
int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] >= dep[top[y]])
            x = f[top[x]];
        else
            y = f[top[y]];
    }
    return dep[x] < dep[y] ? x : y;
}
*/

int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  //std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  scanf("%d", &T);
  for (int C = 1; C <= T; C++) {
    printf("Case #%d:\n", C);
    ecnt = idc = 0;
    for (int i = 0; i <= n; i++) {
      head[i] = son[i] = f[i] = siz[i] = 0;
    }
    scanf("%d%d%d", &n, &q, &r);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &a, &b);
      add(a, b);
      add(b, a);
    }
    dfs1(1);
    dfs2(1, 1);
    int ope, x;
    while (q--) {
      scanf("%d%d", &ope, &x);
      if (ope == 0) r = x;
      if (ope == 1) {
        if (x == r) {
          printf("%d\n", n);
        } else if (st[x] <= id[r] && id[r] <= en[x]) {
          //说明r在x的子树内
          printf("%d\n", n - siz[lca2(x, r)]);
        } else {
          printf("%d\n", siz[x]);
        }
      }
    }
  }
  return 0;
}