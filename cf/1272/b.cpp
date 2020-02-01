/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/12
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    string in;
    cin >> in;
    int l = 0, r = 0, u = 0, d = 0;
    for (auto i: in) {
      if (i == 'L') l++;
      if (i == 'R') r++;
      if (i == 'U') u++;
      if (i == 'D') d++;
    }
    l = min(l, r);
    r = min(l, r);
    u = min(u, d);
    d = min(u, d);
    if (l == 0 && u == 0) {
      cout << 0;
      cout << endl;
      continue;
    }
    if (l == 0) {
      cout << 2 << endl;
      cout << "UD" << endl;
      continue;
    }
    if (u == 0) {
      cout << 2 << endl;
      cout << "LR" << endl;
      continue;
    }
    cout << u + l + d + r << endl;
    while (u--) cout << "U";
    while (l--) cout << "L";
    while (d--) cout << "D";
    while (r--) cout << "R";
    cout << endl;
  }
  return 0;
}