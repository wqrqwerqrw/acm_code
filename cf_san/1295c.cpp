// Wqr_
// Time : 20/02/10
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  ios::sync_with_stdio(false),cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    string s, t;
    cin >> s >> t;
    auto check = [&](){
      vector<int> vs(26, 0), vt(26, 0);
      for(auto i : s) vs[i-'a'] = 1;
      for(auto i : t) vt[i-'a'] = 1;
      for(auto i : t) if(!vs[i-'a']) return false;
      return true;
    };
    if(!check()){
      cout << -1 << endl;
      continue;
    }
    int slen = s.length();
    vector<vector<int>> nx(slen, vector<int>(26, slen));
    for(int i = slen - 1; i >= 1; i--){
      nx[i-1] = nx[i];
      nx[i-1][s[i] - 'a'] = i;
    }
    int ans = 0;
    int itt = 0;
    while(itt != t.length()){
      ans++;
      int its = 0;
      if(t[itt] == s.front()){
        its = nx[its][t[itt] - 'a'];
        itt++;
      }
      if(its == slen) continue;
      while(itt != t.length()){
        its = nx[its][t[itt] - 'a'];
        if(its == slen) break;
        itt++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}