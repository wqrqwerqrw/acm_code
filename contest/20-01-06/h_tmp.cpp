#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int maxn = 1e5 + 100;
int dp[(1 << 8) + 7][101][101];
int e[9], p[9], k, m;
int main() {
    int T, d, m, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &d, &m);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &e[i]);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        int len = (1 << n);
        for (int i = 0; i < len; i++)
            for (int j = 0; j <= 100; j++)
                for (int k = 0; k <= 100; k++)
                    dp[i][j][k] = -1e9;
        dp[0][100][0] = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 100; j >= d + 1; j--) {
                for (int k = 0; k <= 99; k++) {
                    dp[i][j - d][max(0, k - m)] =
                        max(dp[i][j][k] + 1, dp[i][j - d][max(0, k - m)]);
                    for (int f = 1; f <= n; f++) {
                        if (((1 << (f - 1)) & i) == 0) {
                            if (max(0, k - m) + p[f] <= 99)
                                dp[i + (1 << (f - 1))][min(100, j - d + e[f])][max(0, k - m) + p[f]] = max(dp[i + (1 << (f - 1))][min(100, j - d + e[f])][max(0, k - m) + p[f]],
                                                                                                           dp[i][j][k] + 1);
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