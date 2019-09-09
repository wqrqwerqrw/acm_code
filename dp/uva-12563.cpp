// Author : Wqr_
// Time : 2019/9/9 18:57:39
// 10ms..

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 50 + 5;
const int tmax = 180 * 50 + 1000;
int dp[nmax][tmax];
int n, t;
int main(){
    int T;
    cin >> T;
    int kase = 0;
    while(T--){
        cin >> n >> t;
        t--;
        int ans = -1;
        int len;
        for(int i = 0; i <= t; i++) dp[0][i] = -1;
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &len);
            for(int j = 0; j <= t; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= len && dp[i-1][j-len] >= 0)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-len] + 1);
                ans = max(ans, dp[i][j]);
           }
        }
        for(int i = t; i >= 0; i--) if(dp[n][i] == ans){
            printf("Case %d: %d %d\n", ++kase, ans + 1, i + 678);
            break;
        }
    }
    return 0;
}
