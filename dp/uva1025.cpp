/*************************************************************************
    > File Name: uva1025.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 16时28分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#define iofuck std::ios::sync_with_stdio(false)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 2000;
const int tmax = 2000;
int n, ts, t[nmax], m1, m2, f[nmax], b[nmax];
// t, i, 0->f, 1->b
bool h[nmax][nmax][2];
bool sumt[nmax];
int dp[tmax][nmax];
int kase = 0;
void solve(){
    for(int i = 1; i <= n; i++){
        dp[ts][i] = INF;
    }
    dp[ts][n] = 0;
    for(int i = ts - 1; i >= 0; i--){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i + 1][j] + 1;
            if(j < n && h[i][j][0] && i + t[j] <= ts){
                dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
            }
            if(j > 1 && h[i][j][1] && i + t[j - 1] <= ts){
                dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
            }
        }
    }
    cout << "Case Number " << ++kase << ": ";
    if(dp[0][1] >= INF) cout << "impossible" << endl;
    else cout << dp[0][1] << endl;
}
int main(){
    while(cin >> n){
        if(!n) break;
        memset(h, 0, sizeof(h));
        sumt[1] = 0;
        cin >> ts;
        for(int i = 1; i <= n - 1; i++){
            cin >> t[i];
        }
        cin >> m1;
        for(int i = 1; i <= m1; i++){
            cin >> f[i];
            int tmp = f[i];
            h[tmp][1][0] = 1;
            for(int j = 2; j <= n; j++){
                tmp = tmp + t[j - 1];
                h[tmp][j][0] = 1;
            }
        }
        cin >> m2;
        for(int i = 0; i < m2; i++){
            cin >> b[i];
            int tmp = b[i];
            h[tmp][n][1] = 1;
            for(int j = n - 1; j >= 1; j--){
                tmp = tmp + t[j];
                h[tmp][j][1] = 1;
            }
        }
        solve();
    }
    return 0;
}
