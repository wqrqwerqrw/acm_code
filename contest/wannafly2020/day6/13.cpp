// Wqr_
// acme : 20/01/17
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#define int long long
using namespace std;
int n, m, w;
const int N = 100 + 10;
const int inf = 998244353;
set<int> ac[12], wa[12];
int ans[N];
int watijiao[N][12];
int k[N][12];
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> w;
  int x, y, c;
  for (int i = 1; i <= w; i++) {
    cin >> x >> y >> c;
    if (c) {
      ac[y].insert(x);
      k[x][y] = max(k[x][y], watijiao[x][y]);
      watijiao[x][y] = 0;
    } else {
      wa[y].insert(x);
      watijiao[x][y]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      k[i][j] = max(k[i][j], watijiao[i][j]);
      // cerr<< deb(i) << deb(j) <<deb(k[i][j])<<endl;
    }
  }
  for (int i = 1; i <= n; i++) {
    int acnum = 0;
    int wanum = 0;
    for (int j = 1; j <= m; j++) {
      if (ac[j].count(i)) acnum++;
      if (wa[j].count(i)) wanum++;
      if (!ac[j].count(i) && ac[j].size()) {
        ans[i] += 20;
        if (ac[j].size() >= (n / 2)) ans[i] += 10;
      }
      ans[i] += k[i][j] * k[i][j];
      if (!ac[j].count(i)) {
        ans[i] += k[i][j] * k[i][j];
      }
    }
    if (acnum == 0 && wanum == 0)
      ans[i] = inf;
    else if (acnum == 0 && wanum != 0)
      ans[i] = 1000000;
    else if (acnum == m)
      ans[i] = 0;
    cout << ans[i] << endl;
  }
  return 0;
}