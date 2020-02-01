// Author : Wqr_
// Time : 2019年06月19日 星期三 22时31分09秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int d;
int a[3];
int main() {
  iofuck;
  cin >> a[0] >> a[1] >> a[2] >> d;
  sort(a, a + 3);
  int ans = 0;
  if (a[1] - a[0] < d) ans += d - (a[1] - a[0]);
  if (a[2] - a[1] < d) ans += d - (a[2] - a[1]);
  cout << ans << endl;
  return 0;
}
