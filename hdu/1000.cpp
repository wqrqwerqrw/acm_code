// Wqr_
// Time : 20/01/31
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int a, b;
  while (cin >> a >> b) {
    auto ans = [&]() { return a + b; };
    cout << ans() << endl;
  }
  return 0;
}