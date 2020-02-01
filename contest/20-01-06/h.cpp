/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/09
#include <bits/stdc++.h>
using namespace std;
//    药的状态 hp   毒条
int dp[1 << 9][101][101];
int e[9], p[9], k, m, n;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &k, &m);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", e + i);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    int len = (1 << n);
    for (int i = 0; i < len; i++)
      for (int j = 0; j <= 100; j++)
        for (int k = 0; k <= 100; k++)
          dp[i][j][k] = -1e9;
    dp[0][100][0] = 0;
    for (int i = 0; i < len; i++) {
      for (int j = 100; j >= k + 1; j--) {
        for (int u = 0; u <= 99; u++) {
          //不嗑药
          int& bky = dp[i][j - k][max(0, u - m)];
          bky = max(bky, dp[i][j][u] + 1);
          //嗑药
          for (int f = 1; f <= n; f++) {
            if (((1 << (f - 1)) & i) == 0 && max(0, u - m) + p[f] <= 99) {
              int& ky = dp[i + (1 << (f - 1))][min(100, j - k + e[f])][max(0, u - m) + p[f]];
              ky = max(ky, dp[i][j][u] + 1);
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < len; i++)
      for (int j = 0; j <= 100; j++)
        for (int k = 0; k <= 99; k++)
          ans = max(ans, dp[i][j][k]);
    printf("%d\n", ans);
  }
  return 0;
}