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
const int nmax = 20000;
int n;
int a[nmax], b[nmax];
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i] >> 1;
    ans += b[i];
  }
  //cout << ans << endl;
  // toadd
  if (ans < 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 && b[i] * 2 < a[i]) {
        b[i]++;
        ans++;
      }
      if (ans == 0) break;
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 && b[i] * 2 > a[i]) {
        b[i]--;
        ans--;
      }
      if (ans == 0) break;
    }
  }
  int tmp = 0;
  for (int i = 0; i < n; i++) tmp += b[i];
  for (int i = 0; i < n; i++) cout << b[i] << endl;
  //cout << tmp << endl;
  return 0;
}