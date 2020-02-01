// Author : Wqr_
// Time : 2019年07月21日 星期日 14时24分41秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
struct stu {
  int id;
  int a, b, c, all;
  void setall() { all = a + b + c; }
} ss[300 + 10];
int main() {
  int n;
  int a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ss[i].a >> ss[i].b >> ss[i].c, ss[i].setall(), ss[i].id = i + 1;
  sort(ss, ss + n, [](stu &a, stu &b) {
    if (a.all == b.all) {
      if (a.a == b.a)
        return a.id < b.id;
      else
        return a.a > b.a;
    } else
      return a.all > b.all;
  });
  for (int i = 0; i < 5; i++) cout << ss[i].id << " " << ss[i].all << endl;
  return 0;
}
