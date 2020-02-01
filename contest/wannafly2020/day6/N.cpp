// Wqr_
// Time : 20/01/18
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  vector<int> v = {1, 2, 3, 5};
  int a, b, c;
  sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
  for (auto i: v)
    if (i) {
      cout << i << endl;
    }
  dbg(a, b, c);
  return 0;
}