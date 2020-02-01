// Author : Wqr_
// Time : 2019年07月21日 星期日 12时28分29秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int main() {
  char in;
  int w11 = 0, l11 = 0;
  int w21 = 0, l21 = 0;
  vector<P> ans11, ans21;
  while (cin >> in) {
    if (in == 'E') break;
    (in == 'W') ? (w11++, w21++) : (l11++, l21++);
    if ((w11 >= 11 || l11 >= 11) && abs(w11 - l11) >= 2)
      ans11.push_back(P(w11, l11)), w11 = l11 = 0;
    if ((w21 >= 21 || l21 >= 21) && abs(w21 - l21) >= 2)
      ans21.push_back(P(w21, l21)), w21 = l21 = 0;
  }
  ans11.push_back(P(w11, l11));
  ans21.push_back(P(w21, l21));
  for (auto tmp: ans11) cout << tmp.first << ":" << tmp.second << endl;
  cout << endl;
  for (auto tmp: ans21) cout << tmp.first << ":" << tmp.second << endl;
  return 0;
}
