// Author : Wqr_
// Time : 2019年08月27日 星期二 19时17分35秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  int w, n;
  cin >> w >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    if (a[r] + a[l] <= w)
      l++, r--, ans++;
    else
      r--, ans++;
  }
  cout << ans << endl;
  return 0;
}
