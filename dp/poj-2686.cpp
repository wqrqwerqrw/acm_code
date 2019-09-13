// Author : Wqr_
// Time : 19/09/12
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int INF = 10000000;
using namespace std;
typedef long long ll;
const int maxm = 30;
const int maxn = 10;
int n, m, p, a, b;
int t[maxn];
int d[maxm][maxm];
double dp[1 << maxn][maxm];
void init() {
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INF;
        }
    }
    memset(d, -1, sizeof(d));
    memset(t, 0, sizeof(t));
}
void IN() {
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int u, v, dis;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> dis;
        u--, v--;
        d[u][v] = dp[v][u] = dis;
    }
}
void solve() {
    dp[0][a] = 0;
    double res = INF;
    for (int s = 0; s < 1 << n; s++) {
        for (int i = 0; i < n; i++)
            if (s >> i & 1) {
                for (int u = 0; u < m; u++) {
                    for (int v = 0; v < m; v++)
                        if (d[u][v] > 0) {
                            int qv = s & ~(1 << i);
                            dp[s][u] = min(dp[s][u],
                                           dp[qv][u] + (double)d[u][v] / t[i]);
                        }
                }
            }
        res = min(res, dp[s][b]);
    }
    if (res == INF) {
        cout << "Impossible" << endl;
    } else {
        cout << res << endl;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    iofuck;
    while (cin >> n >> m >> p >> a >> b) {
        cout << n << m << p << a << b;
        if (!n && !m && !p && !a && !b)
            break;
        a--, b--;
        init();
        IN();
        solve();
    }
    return 0;
}