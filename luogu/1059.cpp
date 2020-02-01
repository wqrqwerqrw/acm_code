// Author : Wqr_
// Time : 2019年07月21日 星期日 13时13分10秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
  iofuck;
  set<int> sett;
  int n, in;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> in, sett.insert(in);
  cout << sett.size() << endl;
  bool flag = 0;
  for (auto i: sett) {
    if (flag) cout << " ";
    flag = 1;
    cout << i;
  }
  return 0;
}
