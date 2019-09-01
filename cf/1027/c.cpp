// Author : Wqr_
// Time : 2019年08月27日 星期二 19时30分20秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll t;
ll n, a, b;
string road;
ll dp[maxn][2];
void solve(){
    ll ans;
    dp[0][0] = b;
    for(int i = 1; i < n; i++){
        if(road[i] == '1' || road[i-1] == '1')
            dp[i][1] = min(dp[i-1][0] + 2*a + 2*b, dp[i-1][1] + a + 2*b);
        else {
            dp[i][0] = min(dp[i-1][0] + a + b, dp[i-1][1] + 2*a + b);
            dp[i][1] = min(dp[i-1][0] + 2*a + 2*b, dp[i-1][1] + a + 2*b);
        }
    }
    ans = min(dp[n-1][0] + a + b, dp[n-1][1] + 2*a + b);
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t--){
        memset(dp, 0x3f, sizeof(dp));
        cin >> n >> a >> b;
        cin >> road;
        solve();
    }
    return 0;
}
