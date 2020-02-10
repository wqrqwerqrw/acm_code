// Wqr_
// Time : 20/02/05
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  std::ios::sync_with_stdio(false),cin.tie(0);
  int n, nn;
  cin >> n;
  nn = n * 2;
  vector<int> a(nn + 2);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  a[nn + 1] = a[1];
  vector<vector<int>> dp(nn + 1, vector<int>(nn + 1));
  for(int len = 2; len <= n; len++){
    for(int i = 1; i + len - 1 <= nn; i++){
      int j = i + len - 1;
      for(int k = i; k < j; k++){
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + a[i] * a[k+1] * a[j+1]);
      }
    }
  }
  int maxn = 0;
  for(int i = 1; i <= n; i++){
    maxn = max(maxn, dp[i][i + n - 1]);
  }
  cout << maxn;
  return 0;
}