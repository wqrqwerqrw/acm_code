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
  vector<vector<int>> val(m+1, vector<int>(n+1));
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cin >> val[i][j];
    }
  }
  auto dp = vector<vector<vector<int>>>(n+m+1, vector<vector<int>>(m+1, vector<int>(m+1)));
  for(int p = 2; p <= n + m - 1; p++){
    for(int i = 1; i <= m && i <= p; i++){
      for (int j = 1; j <= m && j <= p; j++) {
        dp[p][i][j] = max(max(dp[p-1][i-1][j], dp[p-1][i][j-1]), max(dp[p-1][i][j], dp[p-1][i-1][j-1]));
        dp[p][i][j] += i == j ? 0 : val[i][p - i + 1] + val[j][p - j + 1];
      }
    }
  }
  cout << dp[n+m-1][m][m];
  return 0;
}