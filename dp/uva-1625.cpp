// Author : Wqr_
// Time : 19/09/10
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int nmax = 5000 + 50;
char p[nmax], q[nmax];
int sp[30], sq[30], ep[30], eq[30];
int n, m;
int dp[nmax][nmax];
int c[nmax][nmax];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 30; i++) {
            sp[i] = INF;
            sq[i] = INF;
            ep[i] = 0;
            eq[i] = 0;
        }
        scanf("%s", p + 1);
        scanf("%s", q + 1);
        n = strlen(p + 1);
        m = strlen(q + 1);
        //cout << p + 1 << q + 1 << endl;
        for (int i = 1; i <= n; i++) {
            p[i] -= 'A';
        }
        for (int i = 1; i <= m; i++) {
            q[i] -= 'A';
        }
        for (int i = 1; i <= n; i++) {
            sp[p[i]] = min(sp[p[i]], i);
            ep[p[i]] = i;
        }
        for (int i = 1; i <= m; i++) {
            sq[q[i]] = min(sq[q[i]], i);
            eq[q[i]] = i;
        }

        // 填c, 先j后i&&(!j)
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i && !j)
                    continue;
                if (i) {
                    c[i][j] = c[i - 1][j];
                    if (i == sp[p[i]] && sq[p[i]] > j)
                        c[i][j]++;
                    if (i == ep[p[i]] && eq[p[i]] <= j)
                        c[i][j]--;
                }
                if (j) {
                    c[i][j] = c[i][j - 1];
                    if (j == sq[q[j]] && sp[q[j]] > i)
                        c[i][j]++;
                    if (j == eq[q[j]] && ep[q[j]] <= i)
                        c[i][j]--;
                }
            }
        }
        /*
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= m; i++) {
                cout << c[j][i] << " ";
            }
            cout << endl;
        }
        cout << "--" << endl;
        */
        // dp
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i && !j)
                    continue;
                dp[i][j] = INF;
                if (i)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + c[i - 1][j]);
                if (j)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + c[i][j - 1]);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
