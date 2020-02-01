#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define inf (0x3f3f3f3f)
#define lnf (0x3f3f3f3f3f3f3f3f)
#define eps (1e-8)
int sgn(double a) { return a < -eps ? -1 : a < eps ? 0 : 1; }

const int maxn = 100010;

int t;
struct Q {
  int u, v, a, b;
  int l, r;
  int index;
};

int col[maxn];
int cnt[maxn];
ll cs[maxn];
ll ans[maxn];
const int bk = 316;

const int DEG = 20;
vector<Q> query[3];
vector<int> g[maxn];

int n, q;
int a[maxn], b[maxn];

inline bool scan_d(int &num) {
  char in;
  bool IsN = false;
  in = getchar();
  if (in == EOF) return false;
  while (in != '-' && (in < '0' || in > '9')) in = getchar();
  if (in == '-') {
    IsN = true;
    num = 0;
  } else
    num = in - '0';
  while (in = getchar(), in >= '0' && in <= '9') {
    num *= 10, num += in - '0';
  }
  if (IsN) num = -num;
  return true;
}

void initHash() {
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int p = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  }
}

int L[maxn];
int R[maxn];
int d[maxn];
int tot = 0;

void dfs(int u, int fa, int dep) {
  L[u] = ++tot;
  d[u] = dep;
  col[tot] = a[u];
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == fa) continue;
    dfs(v, u, dep + 1);
  }
  R[u] = tot;
}

bool cmp(Q a, Q b) {
  if (a.l / bk == b.l / bk)
    return a.r < b.r;
  else
    return a.l / bk < b.l / bk;
}

/// find_block
int block[maxn], bcnt, bsize;
int stk[maxn], top;

void add_block(int &cnt) {
  while (cnt--) block[stk[--top]] = bcnt;
  bcnt++;
  cnt = 0;
}

void rest_block() {
  while (top) block[stk[--top]] = bcnt - 1;
}

int dfs_block(int u, int f) {
  int s = 0;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == f) continue;
    s += dfs_block(v, u);
    if (s >= bsize) add_block(s);
  }
  stk[top++] = u;
  s++;
  if (s >= bsize) add_block(s);
  return s;
}

void init_block() {
  bsize = bk;
  dfs_block(1, 0);
  rest_block();
}

/// ask_rmq
int fa[DEG][maxn];
int dep[maxn];

void dfs_lca(int u, int f, int depth) {
  dep[u] = depth;
  fa[0][u] = f;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v != f) dfs_lca(v, u, depth + 1);
  }
}

void init_lca() {
  dfs_lca(1, -1, 0);
  for (int k = 0; k + 1 < DEG; ++k) {
    for (int u = 1; u <= n; ++u) {
      if (fa[k][u] == -1)
        fa[k + 1][u] = -1;
      else
        fa[k + 1][u] = fa[k][fa[k][u]];
    }
  }
}

int ask_lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = 0; k < DEG; ++k) {
    if ((dep[u] - dep[v]) & (1 << k)) u = fa[k][u];
  }
  if (u == v) return u;
  for (int k = DEG - 1; k >= 0; --k) {
    if (fa[k][u] != fa[k][v])
      u = fa[k][u], v = fa[k][v];
  }
  return fa[0][u];
}
/// modui
bool vis[maxn];

void xorNode(int u) {
  if (vis[u]) {
    vis[u] = false;
    cs[cnt[a[u]]] -= b[a[u]];
    cnt[a[u]]--;
    cs[cnt[a[u]]] += b[a[u]];
  } else {
    vis[u] = true;
    cs[cnt[a[u]]] -= b[a[u]];
    cnt[a[u]]++;
    cs[cnt[a[u]]] += b[a[u]];
  }
}

void xorPathWithoutLca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  while (dep[u] != dep[v])
    xorNode(u), u = fa[0][u];
  while (u != v)
    xorNode(u), u = fa[0][u], xorNode(v), v = fa[0][v];
}

void moveNode(int u, int v, int taru, int tarv) {
  xorPathWithoutLca(u, taru);
  xorPathWithoutLca(v, tarv);
  //printf("debug %d %d\n", ask_lca(u, v), ask_lca(taru, tarv));
  xorNode(ask_lca(u, v));
  xorNode(ask_lca(taru, tarv));
}

bool cmp2(Q a, Q b) {
  if (block[a.u] == block[b.u])
    return block[a.v] < block[b.v];
  else
    return block[a.u] < block[b.u];
}

void solve() {
  scan_d(t);
  int c = 0;
  while (t--) {
    tot = 0;
    memset(cs, 0, sizeof(cs));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    query[1].clear();
    query[2].clear();
    scan_d(n);
    scan_d(q);
    for (int i = 1; i <= n; i++) {
      scan_d(a[i]);
    }
    initHash();
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scan_d(u);
      scan_d(v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, -1, 1);
    init_block();
    init_lca();
    for (int i = 0; i < q; i++) {
      int op, u, v, a, b;
      scan_d(op);
      scan_d(u);
      scan_d(v);
      scan_d(a);
      scan_d(b);
      query[op].push_back(Q{u, v, a, b, L[u], R[u], i});
    }
    sort(query[1].begin(), query[1].end(), cmp);

    int pl = 1, pr = 0;

    for (int i = 0; i < query[1].size(); i++) {
      int index = query[1][i].index;
      if (pr < query[1][i].r) {
        for (int j = pr + 1; j <= query[1][i].r; j++) {
          cs[cnt[col[j]]] -= b[col[j]];
          cnt[col[j]]++;
          cs[cnt[col[j]]] += b[col[j]];
        }
      } else {
        for (int j = pr; j > query[1][i].r; j--) {
          cs[cnt[col[j]]] -= b[col[j]];
          cnt[col[j]]--;
          cs[cnt[col[j]]] += b[col[j]];
        }
      }
      pr = query[1][i].r;
      if (pl < query[1][i].l) {
        for (int j = pl; j < query[1][i].l; j++) {
          cs[cnt[col[j]]] -= b[col[j]];
          cnt[col[j]]--;
          cs[cnt[col[j]]] += b[col[j]];
        }
      } else {
        for (int j = pl - 1; j >= query[1][i].l; j--) {
          cs[cnt[col[j]]] -= b[col[j]];
          cnt[col[j]]++;
          cs[cnt[col[j]]] += b[col[j]];
        }
      }
      pl = query[1][i].l;
      ans[index] = __gcd(cs[query[1][i].a], cs[query[1][i].b]);
    }
    memset(cs, 0, sizeof(cs));
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < query[2].size(); i++) {
      if (block[query[2][i].u] > block[query[2][i].v]) swap(query[2][i].u, query[2][i].v);
    }
    sort(query[2].begin(), query[2].end(), cmp2);

    int nowu = 1, nowv = 1;
    xorNode(1);
    for (int i = 0; i < query[2].size(); i++) {
      int index = query[2][i].index;
      moveNode(nowu, nowv, query[2][i].u, query[2][i].v);
      ans[index] = __gcd(cs[query[2][i].a], cs[query[2][i].b]);
      nowu = query[2][i].u, nowv = query[2][i].v;
    }
    printf("Case #%d:\n", ++c);
    for (int i = 0; i < q; i++) {
      printf("%lld\n", ans[i]);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("1.in", "r", stdin);
#endif
  solve();
  return 0;
}