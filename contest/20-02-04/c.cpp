// Wqr_
// Time : 20/02/05
#include <bits/stdc++.h>
using ll = long long;
#define int long long
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  std::ios::sync_with_stdio(false),cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    vector<int> lw, rw;
    for(int i = 0; i < n; i++){
      int in;
      cin >> in;
      if(i < n / 2) lw.push_back(in);
      else rw.push_back(in);
    }
    auto getsum = [&](vector<int>& in){
      vector<int> ret;
      for(int i = 0; i < (1 << in.size()); i++){
        int s = 0;
        for(int j = 0; j < in.size(); j++){
          if(i&(j<<1)) s+= in[j];
        }
        ret.push_back(s);
      }
      return ret;
    };
    auto suml = getsum(lw);
    auto sumr = getsum(rw);
  }
  return 0;
}