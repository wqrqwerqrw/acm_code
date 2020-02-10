// Wqr_
// Time : 20/02/03
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  std::ios::sync_with_stdio(false),cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> maxits;
    int flag = 1;
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    int pend = n - 1, eend = 0, minn = 1e9;
    for(int i = 0; i < n; i++){
      if(a[i] < i) break;
      pend = i;
    }
    for(int i = n - 1; i >= 0; i--){
      if(a[i] < (n - 1) - i) break;
      eend = i;
    }
    if(pend >= eend) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}