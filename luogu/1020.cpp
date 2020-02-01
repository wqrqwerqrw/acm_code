// Wqr_
// Time : 20/01/22
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  vector<int> a;
  int in;
  while (cin >> in) a.push_back(in);
  vector<int> up, dn;
  up.push_back(a[0]);
  dn.push_back(a[0]);
  for (int i = 1; i < a.size(); i++) {
    if (a[i] <= dn.back())
      dn.push_back(a[i]);
    else
      *upper_bound(dn.begin(), dn.end(), a[i], greater<int>()) = a[i];
    if (a[i] > up.back())
      up.push_back(a[i]);
    else
      *lower_bound(up.begin(), up.end(), a[i]) = a[i];
  }
  cout << dn.size() << endl;
  cout << up.size() << endl;
  return 0;
}