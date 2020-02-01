// Wqr_
// Time : 20/01/30
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<int> f(n + 1, 0);
    function<int(int)> getf = [&](int in) {
      return f[in] == in ? in : f[in] = getf(f[in]);
    };
    auto merge = [&](int a, int b) {
      int ra = getf(a);
      int rb = getf(b);
      if (ra > rb)
        f[ra] = rb;
      else
        f[rb] = ra;
    };
    for (int i = 0; i <= n; i++) f[i] = i;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
      merge(u, v);
    }
    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
      if (f[i] == i) {
        G[0].push_back(i);
        ans1++;
      }
    }
    cout << ans1 << endl;
    vector<int> vis(n + 1, 0);
    vector<int> ans;
    auto bfs = [&](int x) {
      priority_queue<int, vector<int>, greater<int>> q;
      q.push(x);
      while (!q.empty()) {
        int now = q.top();
        q.pop();
        if (vis[now]) continue;
        vis[now] = 1;
        ans.push_back(now);
        for (auto i: G[now]) {
          if (!vis[i]) {
            q.push(i);
          }
        }
      }
    };
    bfs(0);
    for (int i = 1; i < ans.size(); i++) {
      if (i != 1) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}