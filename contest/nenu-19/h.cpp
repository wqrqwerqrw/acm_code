// Author : Wqr_
// Time : 2019年07月22日 星期一 13时32分39秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  int in;
  cin >> in;
  int ans = in / 10 + 1;
  int ge = in % 10 / 2;
  if (ge % 2 != 0) ans++;
  cout << ans << endl;
  return 0;
}
