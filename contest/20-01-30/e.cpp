// Wqr_
// Time : 20/01/30
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
int n;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    auto b = a;
    sort(b.begin(), b.end());
    int ans = n;
    for (int i = n; i >= 0; i--) {
      if (a[i] == b[ans - 1]) ans--;
    }
    cout << ans << endl;
  }
  return 0;
}