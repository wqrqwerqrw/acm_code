// Author : Wqr_
// Time : 19/09/24
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
#define ttt cout << "<><><>" << endl;
using namespace std;
typedef long long ll;
int n, m;
vector<int> a(110);
int dp[110][10100];
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j == a[i]) dp[i][j] = dp[i - 1][j] + 1;
      if (j > a[i]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
      if (j < a[i]) dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}