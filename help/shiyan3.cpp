// Author : Wqr_
// Time : 2019年06月16日 星期日 17时04分16秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
double in[5];
int main() {
  double ping;
  for (int i = 0; i < 5; i++) {
    cin >> in[i];
    ping += in[i];
  }
  ping = ping / 5;
  double tmp = 0;
  for (int i = 0; i < 5; i++) {
    tmp += (in[i] - ping) * (in[i] - ping);
  }
  cout << "--------" << endl;
  cout << ping << endl;
  cout << pow(tmp / 20, 0.5);
  return 0;
}
