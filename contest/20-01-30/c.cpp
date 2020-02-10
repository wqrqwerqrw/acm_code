// Wqr_
// Time : 20/02/01
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
    int n, m, k;
    cin >> n;
    vector<int> a(n + 1), b(n);
    vector<int> c(n + 1), sum(n + 1);
    set<pair<int, int>> st1, st2;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      c[a[i]]++;
      sum[a[i]] += 2;
    }
    for (int i = 1; i <= n; i++) {
      if (c[i]) {
        st1.insert({sum[i], i});
        st2.insert({i, c[i]});
      }
    }
    if (st1.rbegin()->first > n) {
      cout << "Impossible" << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      st1.erase({sum[a[i]], a[i]});
      if (--sum[a[i]] > 0) st1.insert({sum[a[i]], a[i]});
      if (st1.rbegin()->first == n - i) {
        b[i] = st1.rbegin()->second;
      } else {
        if (a[i] == st2.begin()->first)
          b[i] = (++st2.begin())->first;
        else
          b[i] = st2.begin()->first;
      }
      st1.erase({sum[b[i]], b[i]});
      st2.erase({b[i], c[b[i]]});
      if (--sum[b[i]] > 0) st1.insert({sum[b[i]], b[i]});
      if (--c[b[i]] > 0) st2.insert({b[i], c[b[i]]});
    }
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << b[i];
    }
    cout << endl;
  }
  return 0;
}