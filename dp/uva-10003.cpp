// Author : Wqr_
// Time : 19/09/11
// classic->130 function with lambda->220ms
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 50 + 5;
int l, n, a[maxn];
int vis[maxn][maxn], d[maxn][maxn];
// dp[i][j] = min(dp[i][k] + dp[k][j]) + a[j] - a[i];
/*
int dp(int i, int j){
    if(i >= j - 1) return 0;
    if(vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int& ans = d[i][j];
    ans = INF;
    for(int k = i + 1; k <= j - 1; k++){
        //ans = min(ans, dp(i, k) +dp(k, j)) + a[j] - a[i];
        int v = dp(i, k) + dp(k, j) + a[j] - a[i];
        if(ans < 0 || v < ans) ans = v;
    }
    return ans;
}
*/

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    function<int(int, int)> dp = dp = [&](int i, int j) {
        if (i >= j - 1)
            return 0;
        if (vis[i][j])
            return d[i][j];
        vis[i][j] = 1;
        int &ans = d[i][j];
        ans = INF;
        for (int k = i + 1; k <= j - 1; k++) {
            // ans = min(ans, dp(i, k) +dp(k, j)) + a[j] - a[i];
            int v = dp(i, k) + dp(k, j) + a[j] - a[i];
            if (ans < 0 || v < ans)
                ans = v;
        }
        return ans;
    };
    while (cin >> l >> n && l) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        a[0] = 0, a[n + 1] = l;
        printf("The minimum cutting is %d.\n", dp(0, n + 1));
    }
    return 0;
}