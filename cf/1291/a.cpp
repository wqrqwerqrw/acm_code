// Wqr_
// Time : 20/02/03
#include <bits/stdc++.h>
using ll = long long;
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
    vector<int> s;
    string in;
    cin >> in;
    for (auto str: in) {
      if (str - '0') s.push_back(str - '0');
    }
    while (s.size() && s.back() % 2 == 0) s.pop_back();
    int sum = 0;
    for (auto i: s) sum += i;
    vector<int> ans;
    if (sum % 2) {
      bool flag = 1;
      for (auto i: s) {
        if (flag && i % 2) {
          flag = 0;
          continue;
        }
        ans.push_back(i);
      }
    } else {
      ans = s;
    }
    while (ans.size() && ans.back() % 2 == 0) ans.pop_back();
    if (ans.size()) {
      for (auto i: ans) if(i) cout << i;
      cout << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}