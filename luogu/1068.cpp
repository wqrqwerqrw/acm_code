// Author : Wqr_
// Time : 2019年07月21日 星期日 13时18分13秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int n, m, k, s, ans_s, ans_num = 0;
  cin >> n >> m;
  vector<P> ks(n);
  for (int i = 0; i < n; i++) cin >> k >> s, ks[i] = P(k, s);
  sort(ks.begin(), ks.end(), [](P &a, P &b) {
    if (a.second == b.second)
      return a.first < b.first;
    else
      return a.second > b.second;
  });
  m = (int)(m * 1.5);
  ans_s = ks[m - 1].second;
  for (auto i: ks)
    if (i.second >= ans_s) ans_num++;
  cout << ans_s << " " << ans_num << endl;
  for (auto i: ks)
    if (i.second >= ans_s) cout << i.first << " " << i.second << endl;
  return 0;
}
