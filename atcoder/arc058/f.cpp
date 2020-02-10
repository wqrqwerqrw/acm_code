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
  int n, k;
  cin >> n >> k;
  vector<string> s(n+1);
  vector<string> dp(k+1, "\256");
  dp[0] = "";
  for(int i = 1; i <= n; i++){
    cin >> s[i];
  }
  auto minst = [&](const string& a, const string& b){
    if(a < b) return a;
    return b;
  };
  for(int i = 1; i <= n; i++){
    string cur = s[i];
    int curl = cur.length();
    for(int j = k; j >= curl; j--){
      dp[j] = minst(dp[j], minst(dp[j], dp[j-curl] + cur));
    }
  }
  cout << dp[k] << "\n";
  return 0;
}