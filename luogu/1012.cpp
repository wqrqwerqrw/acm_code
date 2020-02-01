// Author : Wqr_
// Time : 2019年07月22日 星期一 17时53分11秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  int n;
  string a[21];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, [](string a, string b) { return a + b > b + a; });
  for (auto i: a) cout << i;
  return 0;
}
