/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/05
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
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    if (n < 6) {
      cout << "0 0 0" << endl;
      continue;
    }
    int mid = n / 2;
    int g = 1, s = 0, b = 0;
    int gend, send, bend;
    for (int i = 1; i < mid; i++) {
      if (p[i] == p[0]) {
        g++;
      } else {
        gend = i;
        break;
      }
    }
    if (gend != mid)
      s++;
    else {
      cout << "0 0 0" << endl;
      continue;
    }
    int cursmax = p[gend];
    for (int i = gend + 1; i < mid; i++) {
      if (p[i] == cursmax) {
        s++;
      } else {
        if (s <= g) {
          cursmax = p[i];
          s++;
        } else {
          send = i;
          break;
        }
      }
    }
    for (int i = send; i < mid; i++) {
      if (p[i] > p[mid]) {
        b++;
      }
    }
    if (g >= s || g >= b) {
      cout << "0 0 0" << endl;
      continue;
    }
    if (g && s && b) {
      cout << g << " " << s << " " << b << endl;
    } else {
      cout << "0 0 0" << endl;
    }
  }
  return 0;
}