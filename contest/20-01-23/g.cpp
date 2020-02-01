// Wqr_
// Time : 20/01/23
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
struct Q {
  int u, v, a, b, id;
};
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int _ = 1; _ <= T; _++) {
    cout << "Case #" << _ << ":" << endl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<vector<Q>> q(3);
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
    }
    auto B = A;
    sort(B.begin() + 1, B.end());
    int len = unique(B.begin() + 1, B.end()) - B.begin() - 1;
    for (int i = 1; i <= n; i++) A[i] = lower_bound(B.begin() + 1, B.end(), A[i]) - B.begin();
    int op, u, v, a, b;
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    vector<int> siz(n + 1), dep(n + 1), f(n + 1, 0), son(n + 1, 0);
    vector<int> st(n + 1), en(n + 1), top(n + 1), dfsxu(n + 1);
    function<void(int)> dfs1 = [&](int x) {
      siz[x] = 1;
      dep[x] = dep[f[x]] + 1;
      for (auto nx: G[x]) {
        if (nx == f[x]) continue;
        f[nx] = x;
        dfs1(nx);
        siz[x] += siz[nx];
        if (!son[x] || siz[son[x]] < siz[nx]) son[x] = nx;
      }
    };
    int idc = 0;
    function<void(int, int)> dfs2 = [&](int x, int tp) {
      st[x] = ++idc;
      dfsxu[idc] = x;
      top[x] = tp;
      if (son[x]) dfs2(son[x], tp);
      for (auto nx: G[x]) {
        if (nx == f[x] || nx == son[x]) continue;
        dfs2(nx, nx);
      }
      en[x] = idc;
    };
    auto lca = [&](int x, int y) {
      while (top[x] != top[y]) {
        if (dep[top[x]] >= dep[top[y]])
          x = f[top[x]];
        else
          y = f[top[y]];
      }
      return dep[x] < dep[y] ? x : y;
    };
    for (int i = 0; i < m; i++) {
      cin >> op >> u >> v >> a >> b;
      if (op == 1)
        q[op].push_back({st[u], en[u], a, b, i});
      else
        q[op].push_back({u, v, a, b, i});
    }
    vector<int> Ans(m);
    int BL = sqrt(n);
    sort(q[1].begin(), q[1].end(), [&](const Q& a, const Q& b) {
      if (a.u / BL == b.u / BL) return a.v < b.v;
      return a.u / BL < b.u / BL;
    });
    int l = 0, r = 0;
    vector<int> vis(n + 1, 0);
    auto update(int x) {
      if (!vis(x)) {
        vis[x] = 1;
      }
    };
    for (auto i: q[1]) {
      while (L > i.u)
    }
  }
  return 0;
}