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
    int n, x;
    cin >> n >> x;
    string str;
    cin >> str;
    int n0 = 0, ans = 0, balend, bal = 0;
    n0 = count(str.begin(), str.end(), '0');
    balend = n0 - (n - n0);
    for(auto i : str){
      if(balend == 0){
        if(bal == x){
          ans = -1;
          break;
        }
      } else if (abs(x - bal) % abs(balend) == 0 && (x - bal) / balend >= 0){
        ans++;
      }
      i == '0' ? bal++ : bal--;
    }
    cout << ans << endl;
  }
  return 0;
}