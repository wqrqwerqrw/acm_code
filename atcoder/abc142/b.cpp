/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/16
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n;
  cin >> k;
  int tmp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp >= k) ans++;
  }
  cout << ans << endl;
  return 0;
}