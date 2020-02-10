#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100005;
int gi() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') w = 0, ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return w ? x : -x;
}
struct edge {
  int to, next;
} a[N << 1];
int T, n, len, block, BL, m, col[N], o[N], head[N], cnt;
int fa[N], dep[N], sz[N], son[N], top[N], dfn[N], low[N], ref__[N];
int ccnt, bl[N], s[N], tp;
int cnt1, cnt2, vis[N], tot[N];
ll sum[N], ans[N];
struct query1 {
  int l, r, a, b, id;
  bool operator<(const query1 &b) const {
    if (l / BL == b.l / BL) return r < b.r;
    return l / BL < b.l / BL;
  }
} q1[N];
struct query2 {
  int u, v, a, b, id;
  bool operator<(const query2 &b) const {
    if (bl[u] == bl[b.u]) return bl[v] < bl[b.v];
    return bl[u] < bl[b.u];
  }
} q2[N];
void dfs1(int u, int f) {
  fa[u] = f;
  dep[u] = dep[f] + 1;
  sz[u] = 1;
  for (int e = head[u]; e; e = a[e].next) {
    int v = a[e].to;
    if (v == f) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int up) {
  top[u] = up;
  dfn[u] = ++cnt;
  ref__[cnt] = u;
  int ttp = tp;
  if (son[u]) dfs2(son[u], up);
  if (tp - ttp >= block) {
    ++ccnt;
    while (tp > ttp) bl[s[tp--]] = ccnt;
  }
  for (int e = head[u]; e; e = a[e].next) {
    int v = a[e].to;
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
    if (tp - ttp >= block) {
      ++ccnt;
      while (tp > ttp) bl[s[tp--]] = ccnt;
    }
  }
  low[u] = cnt;
  s[++tp] = u;
}
int lca(int u, int v) {
  while (top[u] ^ top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
void update(int x) {
  if (!vis[x]) {
    vis[x] = 1;
    sum[tot[col[x]]] -= o[col[x]];
    tot[col[x]]++;
    sum[tot[col[x]]] += o[col[x]];
  } else {
    vis[x] = 0;
    sum[tot[col[x]]] -= o[col[x]];
    tot[col[x]]--;
    sum[tot[col[x]]] += o[col[x]];
  }
}
void change(int u, int v) {
  while (u ^ v)
    if (dep[u] > dep[v])
      update(u), u = fa[u];
    else
      update(v), v = fa[v];
}
ll Gcd(ll A, ll B) { return B ? Gcd(B, A % B) : A; }
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  T = gi();
  for (int zsy = 1; zsy <= T; zsy++) {
    printf("Case #%d:\n", zsy);
    n = gi();
    m = gi();
    block = pow(n, 0.6);
    BL = pow(n, 0.5);
    for (int i = 1; i <= n; i++) col[i] = o[i] = gi();
    sort(o + 1, o + n + 1);
    len = unique(o + 1, o + n + 1) - o - 1;
    for (int i = 1; i <= n; i++) col[i] = lower_bound(o + 1, o + len + 1, col[i]) - o;
    // for (int i = 0; i <= n; i++) cout << col[i] << "-";
    memset(head, 0, sizeof(head));
    cnt = ccnt = 0;
    memset(son, 0, sizeof(son));
    for (int i = 1, u, v; i < n; i++) {
      u = gi();
      v = gi();
      a[++cnt] = (edge){v, head[u]};
      head[u] = cnt;
      a[++cnt] = (edge){u, head[v]};
      head[v] = cnt;
    }
    dfs1(1, 0);
    cnt = 0;
    dfs2(1, 1);
    while (tp) bl[s[tp--]] = ccnt;
    cnt1 = cnt2 = 0;
    for (int i = 1, opt, u, v, A, B; i <= m; i++) {
      opt = gi();
      u = gi();
      v = gi();
      A = gi();
      B = gi();
      if (dfn[u] > dfn[v]) swap(u, v);
      if (opt == 1)
        q1[++cnt1] = (query1){dfn[u], low[u], A, B, i};
      else
        q2[++cnt2] = (query2){u, v, A, B, i};
    }
    sort(q1 + 1, q1 + cnt1 + 1);
    sort(q2 + 1, q2 + cnt2 + 1);
    int L = 1, R = 0;
    memset(tot, 0, sizeof(tot));
    memset(sum, 0, sizeof(sum));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= cnt1; i++) {
      while (R < q1[i].r) R++, update(ref__[R]);
      while (R > q1[i].r) update(ref__[R]), R--;
      while (L > q1[i].l) L--, update(ref__[L]);
      while (L < q1[i].l) update(ref__[L]), L++;
      ans[q1[i].id] = Gcd(sum[q1[i].a], sum[q1[i].b]);
    }
    memset(tot, 0, sizeof(tot));
    memset(sum, 0, sizeof(sum));
    memset(vis, 0, sizeof(vis));
    change(q2[1].u, q2[1].v);
    int gg = lca(q2[1].u, q2[1].v);
    update(gg);
    ans[q2[1].id] = Gcd(sum[q2[1].a], sum[q2[1].b]);
    update(gg);
    for (int i = 2; i <= cnt2; i++) {
      change(q2[i].u, q2[i - 1].u);
      change(q2[i].v, q2[i - 1].v);
      gg = lca(q2[i].u, q2[i].v);
      update(gg);
      ans[q2[i].id] = Gcd(sum[q2[i].a], sum[q2[i].b]);
      update(gg);
    }
    for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  }
  return 0;
}