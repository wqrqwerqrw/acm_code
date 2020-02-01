/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/17
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  int a1, b1, c1, aaa1, aaa2;
  int a2, b2, c2;

  while (t--) {
    cin >> a1 >> b1 >> c1;
    a2 = a1;
    b2 = b1;
    c2 = c1;
    aaa1 = 0;
    aaa2 = 0;
    while (a1 > 0 && b1 >= 2) {
      a1--;
      b1 -= 2;
      aaa1 += 3;
    }
    while (b1 > 0 && c1 >= 2) {
      b1--;
      c1 -= 2;
      aaa1 += 3;
    }
    while (b2 > 0 && c2 >= 2) {
      b2--;
      c2 -= 2;
      aaa2 += 3;
    }
    while (a2 > 0 && b2 >= 2) {
      a2--;
      b2 -= 2;
      aaa2 += 3;
    }
    cout << max(aaa1, aaa2) << endl;
  }
  return 0;
}