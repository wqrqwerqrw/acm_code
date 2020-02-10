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
  cin >> n;
  vector<int> a(n + 1);
  char ch;
  for(int i = 1; i <= n; i++){
    cin >> ch;
    if(ch == 'A') a[i] = 1;
    else if (ch == 'C') a[i] = 2;
    else if (ch == 'G') a[i] = 3;
    else if (ch == 'T') a[i] = 4;
  }
  cin >> m;
  vector<int> b(m + 1);
  for(int i = 1; i <= m; i++){
    cin >> ch;
    if(ch == 'A') b[i] = 1;
    else if (ch == 'C') b[i] = 2;
    else if (ch == 'G') b[i] = 3;
    else if (ch == 'T') b[i] = 4;
  }
  vector<vector<int>> val = {
    {0, 0, 0, 0, 0, 0},
    {0, 5, -1, -2, -1, -3},
    {0, -1, 5, -3, -2, -4},
    {0, -2, -3, 5, -2, -2},
    {0, -1, -2, -2, 5, -1},
    {0, -3, -4, -2, -1, 0}
  };
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e6));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + val[a[i]][5];
  }
  for (int i = 1; i <= m; i++) {
    dp[0][i] = dp[0][i - 1] + val[5][b[i]];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + val[a[i]][5]);
      dp[i][j] = max(dp[i][j], dp[i][j - 1] + val[5][b[j]]);
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + val[a[i]][b[j]]);
    }
  }
  cout << dp[n][m];
  return 0;
}