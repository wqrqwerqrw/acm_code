// Wqr_
// Time : 20/02/10
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e5 + 100;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  int T;
  cin >> T;
  while(T--){
    char s[N], t[N];
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int slen = strlen(s + 1);
    int tlen = strlen(t + 1);
    auto check = [&](){
      vector<int> vs(26, 0), vt(26, 0);
      for(int i = 1; i <= slen; i++)
        vs[s[i] - 'a'] = 1;
      for(int i = 1; i <= tlen; i++)
        if (!vs[t[i] - 'a']) return false;
      return true;
    };
    if(!check()){
      cout << -1 << endl;
      continue;
    }
    vector<vector<int>> nx(slen + 1, vector<int>(26, slen + 1));
    for(int i = slen; i >= 1; i--){
      nx[i-1] = nx[i];
      nx[i-1][s[i] - 'a'] = i;
    }
    int ans = 0;
    int itt = 1;
    while(itt != tlen + 1){
      ans++;
      int its = 0;
      while(itt != tlen + 1){
        its = nx[its][t[itt] - 'a'];
        if(its == slen + 1) break;
        itt++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}