// Author : Wqr_
// Time : 2019年07月21日 星期日 12时55分32秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  int n, a[110], mid, all, ans;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], all += a[i];
  all /= n;
  for (int i = 0; i < n; i++)
    if (a[i] - all) a[i + 1] += a[i] - all, ans++;
  cout << ans << endl;
  return 0;
}
