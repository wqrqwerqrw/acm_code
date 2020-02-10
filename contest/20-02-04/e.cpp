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
    string in;
    cin >> in;
    for(auto &i : in){
      if(i == 'y') continue;
      if(i == 'z') i = 'b';
      break;
    }
    cout << in << endl;
  }
  return 0;
}