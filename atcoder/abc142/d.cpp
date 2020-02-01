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
  ll a, b;
  cin >> a >> b;
  ll c = __gcd(a, b);
  ll d = c, ans = 1;
  for (ll i = 2; i * i <= c; i++) {
    if (c % i == 0) {
      ans++;
      while (c % i == 0) c /= i;
    }
  }
  if (c != 1) ans++;
  cout << ans << endl;
  return 0;
}