/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/10
#include <bits/stdc++.h>
#define first fi
#define second se
using namespace std;
typedef long long ll;
#define int ll
int n;
int32_t main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &i: a) {
      cin >> i;
      sum += i;
    }
    ll last = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      last = max(0LL, last) + a[i];
      ans = max(ans, last);
    }

    last = 0;
    for (int i = 1; i < n; i++) {
      last = max(0LL, last) + a[i];
      ans = max(ans, last);
    }

    // cout << sum << " " << ans << endl;
    if (sum > ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}