/*
translation:
    一张图由n个点构成，并且若干个点之间由双向边连成。有若干票，每次走完一个边花费一张票
    花费时间是边的长度 / 票的权重。求从指定起点到终点所用的最短时间。
solution:
    状压dp
    首先观察数据，发现n比较小，很容易看出对n进行状态压缩。设置dp[s][v]表示状态s下，到达节点v所用的最短时间。
    其中s表示已经使用的车票的集合。即可写出状态转移。
note:
    # 最后输出时候是%.3lf就WA，%.3f就过，不知道为啥？
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>

using namespace std;
const int maxm = 35;
const int maxn = 10;
const int inf = 1000000007;

int m, n, p, a, b; //m是城市数量，n是车票数量，p是道路数量，a是起点城市，b是终点城市
int dist[maxm][maxm], ticket[maxn];
double dp[400][maxm];

int main()
{
    freopen("in.txt", "r", stdin);
    while (~scanf("%d%d%d%d%d", &n, &m, &p, &a, &b)) {
        if (!m && !n && !p && !a && !b)
            break;
        // printf("# %d %d %d %d %d\n", m, n, p, a, b);

        memset(dist, -1, sizeof(dist));
        memset(ticket, 0, sizeof(ticket));
        for (int i = 0; i < n; i++)
            scanf("%d", &ticket[i]);

        int u, v, d;
        for (int i = 0; i < p; i++) {
            scanf("%d%d%d", &u, &v, &d);
            dist[u][v] = d;
            dist[v][u] = d;
        }

        for (int i = 0; i < 400; i++) {
            for (int j = 0; j <= 35; j++) {
                dp[i][j] = inf;
            }
        }

        dp[0][a] = 0;
        double ans = inf;
        for (int s = 0; s < 1 << n; s++) {
            for (int i = 0; i < n; i++)
                if (s >> i & 1) {
                    for (int u = 1; u <= m; u++) {
                        for (int v = 1; v <= m; v++)
                            if (v != u && dist[u][v] >= 0) {
                                dp[s][v] = min(dp[s][v], dp[s & ~(1 << i)][u] + (double)dist[u][v] / ticket[i]);
                            }
                    }
                }
            ans = min(ans, dp[s][b]);
        }
        if (ans >= inf)
            printf("Impossible\n");
        else
            printf("%.3f\n", ans);
    }
    return 0;
}