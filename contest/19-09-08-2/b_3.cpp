// Author : Wqr_
// Time : 2019/9/8 16:09:35

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int vmax = 2000 + 20;
struct edge {
  int to, cost;
};
vector<edge> G[vmax];
typedef pair<int, int> P;
int v, e, s, k, chu;
int d[vmax];
int nor[vmax];
int dij(int in) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + v, INF);
  d[in] = 0;
  que.push(P(0, in));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int V = p.second;
    if (d[V] < p.first) continue;
    for (int i = 0; i < G[V].size(); i++) {
      edge e = G[V][i];
      if (d[e.to] > d[V] + e.cost) {
        d[e.to] = d[V] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  int maxnum = -1;
  for (int i = 0; i < v; i++) {
    if (d[i] == 0) continue;
    if (d[i] >= INF) continue;
    maxnum = max(maxnum, d[i]);
  }
  return maxnum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> v >> e >> s >> k >> chu;
    for (int i = 0; i < k; i++) {
      cin >> nor[i];
      nor[i]--;
    }
    int a, b, c;
    for (int i = 0; i < e; i++) {
      cin >> a >> b >> c;
      --a, --b;
      edge e1, e2;
      e1.to = b;
      e1.cost = c;
      e2.to = a;
      e2.cost = c;
      G[a].push_back(e1);
      G[b].push_back(e2);
    }
    int maxnor = -1;
    for (int i = 0; i < k; i++) {
      maxnor = max(maxnor, dij(nor[i]));
    }
    int maxher = dij(s - 1);
    double chuher = (double)maxher / chu;
    if (chuher <= maxnor)
      cout << maxher << endl;
    else
      cout << maxnor << endl;
  }
  return 0;
}
