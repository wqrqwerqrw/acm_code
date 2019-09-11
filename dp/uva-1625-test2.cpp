#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f
#define LL long long
#define N 5005
using namespace std;
unsigned char c;
int dp[N][N], cnt[N][N];
int bf[100], bs[100], ef[100], es[100];
char f[N], s[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", f + 1, s + 1);
        int lenf = strlen(f + 1), lens = strlen(s + 1);
        for (c = 'A'; c <= 'Z'; c++) bf[c] = bs[c] = INF, ef[c] = es[c] = 0;
        for (int i = 1; i <= lenf; i++) {
            c = f[i];
            bf[c] = min(i, bf[c]);
            ef[c] = i;
        }
        for (int i = 1; i <= lens; i++) {
            c = s[i];
            bs[c] = min(i, bs[c]);
            es[c] = i;
        }
        for (int i = 0; i <= lenf; i++) {
            for (int j = 0; j <= lens; j++) {
                if (i) {
                    cnt[i][j] = cnt[i - 1][j];
                    c = f[i];
                    if (bf[c] == i && bs[c] > j) cnt[i][j]++;
                    if (ef[c] == i && es[c] <= j) cnt[i][j]--;
                }
                if (j) {
                    cnt[i][j] = cnt[i][j - 1];
                    c = s[j];
                    if (bs[c] == j && bf[c] > i) cnt[i][j]++;
                    if (es[c] == j && ef[c] <= i) cnt[i][j]--;
                }
            }
        }
        for (int i = 0; i <= lenf; i++) {
            for (int j = 0; j <= lens; j++) {
                cout << cnt[i][j] << " ";
            }
            cout << endl;
        }
        cout << "--";
        for (int i = 0; i <= lenf; i++)
            for (int j = 0; j <= lens; j++) {
                if (!i && !j) continue;
                dp[i][j] = INF;
                if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + cnt[i - 1][j]);
                if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + cnt[i][j - 1]);
            }
        printf("%d\n", dp[lenf][lens]);
    }
    return 0;
}