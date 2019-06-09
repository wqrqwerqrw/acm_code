/*************************************************************************
    > File Name: uva-1347.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 18时21分39秒
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
using namespace std;
typedef long long ll;
int n;
const int nmax = 1000 + 5;
struct point{
    int x, y;
}ps[nmax];
double dis[nmax][nmax];
double dp[nmax][nmax];
double fa(int in){
    return in * in;
}
void getdis(){
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            dis[i][j] =  sqrt(fa(ps[i].x - ps[j].x) + fa(ps[i].y - ps[j].y));
            dis[j][i] = dis[i][j];
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    */
}
void solve(){
    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j < i; j++){
            if(i == n - 1) 
                dp[i][j] = dis[i][n] + dis[j][n];
            else 
                dp[i][j] = min(dp[i + 1][j] + dis[i][i + 1], dp[i + 1][i] + dis[j][i + 1]);
        }
    }
    //注意dp中i比j要大
    printf("%.2f\n", dp[2][1] + dis[1][2]);
}
int main(){
    while(scanf("%d", &n) == 1){
        memset(dp, 0x3f, sizeof(dp));
        int x, y;
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &x, &y);
            ps[i].x = x;
            ps[i].y = y;
        }
        getdis();
        solve();
    }
    return 0;
}
