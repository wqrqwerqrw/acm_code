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
  std::ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> num(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      num[a[i]]++;
    }
    bool flag = [&]() {
      for (int i = 1; i <= n; i++)
        if (num[i] > n / 2) return true;
      return false;
    };
    if (flag) {
      cout << "Impossible" << endl;
      continue;
    }
  }
  return 0;
}