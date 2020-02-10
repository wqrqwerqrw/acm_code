#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  ios::sync_with_stdio(false),cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int n, suma = 0, ans = 0;
    cin >> n;
    vector<pair<int, int>> c(n);
    vector<int> sw(n);
    for(int i = 0; i < n; i++){
      cin >> c[i].first >> c[i].second;
      suma += c[i].first;
    }
    for(int i = 0; i < n; i++) sw[i] = suma - c[i].first;
    for(int i = 0; i < n; i++){
      int tmp = min(sw[i], c[i].second);
      if(suma < tmp) {
        ans += suma;
        break;
      }
      ans += tmp;
      suma -= tmp;
    }
    cout << ans << endl;
  }
  return 0;
}