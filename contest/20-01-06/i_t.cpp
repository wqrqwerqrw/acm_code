// Wqr_
// Time : 20/02/01
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  for (int C = 1; C <= T; C++) {
    cout << "Case #" << C << ":" << endl;
    int n, q, r, idc = 0;
    cin >> n >> q >> r;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    vector<int> siz(n + 1), dep(n + 1), f(n + 1), son(n + 1);
    function<void(int)> dfs1 = [&](int x) {
      siz[x] = 1;
      dep[x] = dep[f[x]] + 1;
      for (int nx: G[x]) {
        if (nx == f[x]) continue;
        f[nx] = x;
        dfs1(nx);
        siz[x] += siz[nx];
        if (!son[x] || siz[son[x]] < siz[nx]) son[x] = nx;
      }
    };
    vector<int> st(n + 1), en(n + 1), top(n + 1);
    function<void(int, int)> dfs2 = [&](int x, int tp) {
      st[x] = ++idc;
      top[x] = tp;
      if (son[x]) dfs2(son[x], tp);
      for (int nx: G[x]) {
        if (nx == f[x] || nx == son[x]) continue;
        dfs2(nx, nx);
      }
      en[x] = idc;
    };
    dfs1(1);
    dfs2(1, 1);
    auto lca2 = [&](int x, int y) {
      int t;
      while (top[x] != top[y]) t = top[y], y = f[top[y]];
      return x == y ? t : son[x];
    };
    int ope, x;
    while (q--) {
      cin >> ope >> x;
      if (ope == 0) r = x;
      if (ope == 1) {
        if (x == r) {
          cout << n << endl;
        } else if (st[x] <= st[r] && st[r] <= en[x]) {
          cout << n - siz[lca2(x, r)] << endl;
        } else {
          cout << siz[x] << endl;
        }
      }
    }
  }
  return 0;
}