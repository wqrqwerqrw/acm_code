// Author : Wqr_
// Time : 2019年07月19日 星期五 18时37分03秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int n;
int main() {
  cin >> n;
  int in;
  bool iffu = 0;
  for (int i = n; i >= 1; i--) {
    cin >> in;
    if (in < 0)
      iffu = 1, in = -in;
    else
      iffu = 0;
    if (in != 0) {
      if (iffu)
        printf("-");
      else if (i != n)
        printf("+");
      if (in != 1) cout << in;
      if (i != 1)
        printf("x^%d", i);
      else
        printf("x");
    }
  }
  cin >> in;
  if (in != 0) {
    if (in > 0)
      printf("+%d", in);
    else
      printf("%d", in);
  }
  return 0;
}
