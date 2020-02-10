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
  vector<int> a(nn + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  vector<int> sum(nn + 1);
  for (int i = 1; i <= nn; i++) sum[i] = a[i] + sum[i - 1];
  vector<vector<int>> dp1(nn + 1, vector<int>(nn + 1, 1e9));
  vector<vector<int>> dp2(nn + 1, vector<int>(nn + 1));
  for(int len = 1; len <= n; len++){
    for(int i = 1; i + len - 1 <= nn; i++){
      int j = i + len - 1;
      if(len == 1) dp1[i][j] = dp2[i][j] = 0;
      for(int k = i; k < j; k++){
        dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1]);
        dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  // dbg(dp2[1][3]);
  int maxn, minn = 1e9;
  for(int i = 1; i <= n; i++){
    minn = min(minn, dp1[i][i + n - 1]);
    maxn = max(maxn, dp2[i][i + n - 1]);
  }
  cout << minn << "\n";
  cout << maxn;
  return 0;
}