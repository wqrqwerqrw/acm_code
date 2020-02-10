// Wqr_
// Time : 20/02/06
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  std::ios::sync_with_stdio(false),cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<vector<int>> g(m+2, vector<int>(n+2, -1e9));
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cin >> g[i][j];
    }
  }
  vector<vector<int>> dp(m+2, vector<int>(n + 2, -1e9));
  dp[m+1][n/2+1] = 0;
  for(int i = m; i >= 1; i--){
    for(int j = n; j >= 1; j--){
      dp[i][j] = max(dp[i][j], dp[i+1][j] + g[i][j]);
      if (j != 1) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + g[i][j]);
      if (j != n) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + g[i][j]);
    }
  }
  int ans = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
  return 0;
}