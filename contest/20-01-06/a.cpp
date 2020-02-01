/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____|_     
             |_|    |_____|  */
// Time : 20/01/06
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 50000 + 50;
int g, w, q;
int t[nmax];
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    cout << "Case " << kase << ":" << endl;
    cin >> g >> w;
    for (int i = 0; i < g; i++) {
      cin >> t[i];
    }
    cin >> q;
    int a, b;
    while (q--) {
      cin >> a >> b;
      a--;
      t[a] = b;
      sort(t, t + g);
      vector<vector<int>> vs(w);
      for (int i = 0; i < g; i++) {
        vs[i % w].push_back(t[i]);
      }
      int ans = 0;
      int tmp = 0;
      int last = 0;
      for (auto v: vs) {
        tmp = 0;
        last = 0;
        for (auto i: v) {
          tmp += last + i;
          last = last + i;
        }
        ans += tmp;
      }
      cout << ans << endl;
    }
  }
  return 0;
}