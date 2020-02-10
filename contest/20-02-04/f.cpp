// Wqr_
// Time : 20/02/04
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  std::ios::sync_with_stdio(false),cin.tie(0);
  int T; cin >> T;
  while(T--){
    int n;
    cin >> n;
    vector<int> w(n);
    bool flag = 0;
    for(int i = 0; i < n; i++){
      cin >> w[i];
      if(w[i] % 10) flag = 1;
      w[i] /= 10;
    }
    if(flag){
      cout << -1 << "\n";
      continue;
    }
    auto check = [&](int a, int b, int c){
      vector<int> dp(13);
      for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
          for(int k = 0; k <= c; k++){
            dp[i+j*2+k*5] = 1;
          }
        }
      }
      int ret = 0;
      for(auto i : w){
        if(i >= 10 && i % 10 == 0 && dp[10]) ret = max(ret, i / 10 - 1);
        else if (i >= 10 && i % 10 == 1 && dp[11]) ret = max(ret, i / 10 - 1);
        else if (i >= 10 && i % 10 == 2 && dp[12]) ret = max(ret, i / 10 - 1);
        else if (!dp[i % 10]) ret = 1e9;
        else if (i >= 10) ret = max(ret, i / 10);
      }
      // if(!ret) dbg(a, b, c);
      return ret + a + b + c;
    };
    int ans = 1e9;
    for(int i = 0; i <= 1; i++){
      for(int j = 0; j <= 3; j++){
        for(int k = 0; k <= 1; k++){
          ans = min(ans, check(i, j, k));
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}