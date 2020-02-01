// Author : Wqr_
// Time : 2019年07月22日 星期一 12时12分57秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  iofuck;
  int k, ans = 0;
  string a, b;
  cin >> k;
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++)
    if (k > 0) {
      if (a[i] == b[i]) {
        k--, ans++;
        a[i] = b[i] = '*';
      }
    }
  for (int i = 0; i < a.length(); i++)
    if (k > 0 && a[i] != '*') {
      a[i] = b[i] = '*';
      k--;
    }
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
