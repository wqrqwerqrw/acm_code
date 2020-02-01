// Author : Wqr_
// Time : 2019年06月16日 星期日 16时38分58秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  double s1 = 50;
  double s2;
  while (cin >> s2) {
    s2 = s2 - 70;
    double ans = (s1 * s2) / (s1 + s2);
    cout << ans << endl;
  }
  return 0;
}
