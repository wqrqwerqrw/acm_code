/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/14
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
const int N = 1e5 + 7;
const int inf = 1e9;
vector<int> g[N];
int dp[1 << 17][200];
int32_t main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  // 2 << 17 = 262144
  cin >> n >> m;
  int len = (1 << n);
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = inf;
    }
  }
  return 0;
}