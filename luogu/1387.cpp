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
  int n, m;
  cin >> n >> m;
  auto a = vector<vector<int>>(n+1, vector<int>(m+1, 0));
  auto dp = a;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
      if(a[i][j]) dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
  return 0;
}