// Wqr_
// Time : 20/01/22
#include <bits/stdc++.h>
#define endl "\n"
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
const int N = 1e4 + 100;
struct node {
  int v, w;
  bool operator<(const node& a) const { return w > a.w; }
};
vector<node> G[N];
int n, k, d, dis[N];
bool vis[N];
void dij(int s) {
  for (int i = 1; i <= n + 1; i++) dis[i] = inf;
  dis[s] = 0;
  priority_queue<node> q;
  q.push({s, dis[s]});
  while (!q.empty()) {
    node tmp = q.top();
    q.pop();
    int u = tmp.v;
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto e: G[u]) {
      int v = e.v;
      int w = e.w;
      if (!vis[v] && dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }
}
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  int p, t;
  for (int i = 0; i < k; i++) {
    cin >> p >> t;
    G[p].push_back({p + t, t});
  }
  for (int i = 1; i <= n; i++) {
    if (!G[i].size()) G[i].push_back({i + 1, 0});
  }
  dij(1);
  cout << n - dis[n + 1] << endl;
  return 0;
}