// Wqr_
// Time : 20/02/05
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
struct Q {
  int u, v, w;
};
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> G(n + 1);
  int u, v;
  vector<vector<int>> eid(n + 1, vector<int>(n + 1, -1));
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
    eid[u][v] = i;
    eid[v][u] = i;
  }
  vector<int> dep(n + 1), f(n + 1);
  function<void(int)> dfs1 = [&](int x) {
    for (auto e: G[x]) {
      if (e != f[x]) {
        f[e] = x;
        dep[e] = dep[x] + 1;
        dfs1(e);
      }
    }
  };
  dfs1(1);
  int qnum;
  cin >> qnum;
  vector<Q> q(qnum);
  vector<int> ans(n - 1, 1000000);
  for (auto& i: q) {
    cin >> i.u >> i.v >> i.w;
  }
  sort(q.begin(), q.end(), [](const Q& a, const Q& b) {
    return a.w < b.w;
  });
  for (auto i: q) {
    int u = i.u, v = i.v;
    while (u != v) {
      if (dep[u] < dep[v]) swap(u, v);
      ans[eid[u][f[u]]] = i.w;
      u = f[u];
    }
  }
  for (auto i: q) {
    int u = i.u, v = i.v;
    int mx = 10000000;
    while (u != v) {
      if (dep[u] < dep[v]) swap(u, v);
      mx = min(mx, ans[eid[u][f[u]]]);
      u = f[u];
    }
    if (mx != i.w) {
      cout << -1;
      return 0;
    }
  }
  for (auto i: ans) cout << i << " ";
  return 0;
}