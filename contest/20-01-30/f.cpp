// Wqr_
// Time : 20/01/30
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string in;
    cin >> in;
    int len = in.length();
    cout << in[0];
    for (int i = 1; i < len; i++) {
      if (in[i] != 'a' && in[i] != 'e' && in[i] != 'i' && in[i] != 'o' && in[i] != 'u' && in[i] != 'y') {
        cout << in[i];
      }
    }
    cout << endl;
  }
  return 0;
}