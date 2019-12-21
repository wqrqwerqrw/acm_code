/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/12
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
const int nmax = 2e5 + 100;
int n;
int a[nmax];
int dp[nmax];
bool jo[nmax];
void dfs(int cp, int st, int lp){
    if(cp < 0 || cp >= n) return ;
    if(lp == -1){
        dfs(cp + a[cp], st + 1, cp);
        dfs(cp - a[cp], st + 1, cp);
    }
    if(jo[cp] != jo[lp]){
        dp[lp] = min(st, dp[lp]);
        return ;
    }
    if(jo[cp] == jo[lp] && dp[cp] != inf){
        dp[lp] = min(dp[lp], st + dp[cp]);
        return ;
    }
    dfs(cp + a[cp], st + 1, lp);
    dfs(cp - a[cp], st + 1, lp);
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    memset(dp, inf, sizeof(dp));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        jo[i] = a[i] % 2;
    }
    for(int i = 0; i < n; i++){
        dfs(i, 0, -1);
    }
    for(int i = 0; i < n; i++){
        if(dp[i] != inf) cout << dp[i];
        else cout << -1;
        cout << " ";
    }
    cout << endl;
    return 0;
}