/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/11
#include <bits/stdc++.h>
#define first fi
#define second se
using namespace std;
typedef long long ll;
int main() {
#ifdef Wqr_
  // freopen("in.txt","r",stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll n;
  cin >> n;
  ll a, b;
  for (ll i = 1; i * i < n; i++) {
    if (n % i == 0 && __gcd(i, n / i) == 1) {
      a = i;
      b = n / i;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}