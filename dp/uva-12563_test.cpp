// Author : Wqr_
// Time : 2019/9/9 18:57:39
// 10ms
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 50 + 5;
const int tmax = 180 * 50 + 1000;
int dp[tmax];
int n, t;
int main(){
    int T;
    cin >> T;
    for(int kase = 1; kase <= T; kase++){
        cin >> n >> t;
        t--;
        int ans = -1;
        int len;
        for(int i = 0; i <= t; i++) dp[i] = -1;
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &len);
            for(int j = t; j >= 0; j--){
                if(j >= len && dp[j-len] >= 0){
                    dp[j] = max(dp[j], dp[j-len] + 1);
                }
                ans = max(ans, dp[j]);
            }
        }
        for(int i = t; i >= 0; i--) if(dp[i] == ans){
            printf("Case %d: %d %d\n", kase, ans + 1, i + 678);
            break;
        }
    }
    return 0;
}