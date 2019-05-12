/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月11日 星期六 19时32分53秒
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
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
// 0 rest, 1 gym, 2 contest
bool can[110][3];
int dp[110][3];
void solve(){
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 1;
    if(can[0][1]) dp[0][1] = 0;
    if(can[0][2]) dp[0][2] = 0;
    for(int i = 1; i < n; i++){
        int minn = INF;
        for(int j = 0; j < 3; j++){
            minn = min(minn, dp[i - 1][j]);
        }
        dp[i][0] = minn + 1; 
        if(can[i][1]){
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if(can[i][2]){
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    int minn = INF;
    for(int i = 0; i < 3; i++){
        minn = min(minn, dp[n - 1][i]);
    }
    cout << minn << endl;
}
int main(){
    cin >> n;
    int in;
    for(int i = 0; i < n; i++){
        scanf("%d", &in);
        can[i][0] = 1;
        switch(in){
            case 0:
                can[i][1] = 0;
                can[i][2] = 0;
                break;
            case 1:
                can[i][1] = 0;
                can[i][2] = 1;
                break;
            case 2:
                can[i][1] = 1;
                can[i][2] = 0;
                break;
            case 3:
                can[i][1] = 1;
                can[i][2] = 1;
                break;
        }
    }
    solve();
    return 0;
}
