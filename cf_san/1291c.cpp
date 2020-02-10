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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    k = min(k, m - 1);
    int ans = -1e9;
    for(int i = 0; i <= k; i++){
      int tmp = 1e9;
      for(int j = 0; j <= m - 1 - k; j++){
        int hou = n - (m - 1 - (i + j));
        tmp = min(tmp, max(a[i + j + 1], a[hou]));
      }
      ans = max(ans, tmp);
    }
    cout << ans << endl;
  }
  return 0;
}