/*************************************************************************
    > File Name: poj-2031.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月04日 星期六 20时08分36秒
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
#define MAX_N 110
#define INF 99999999
using namespace std;
int n;
double cost[MAX_N][MAX_N];
double mincost[MAX_N];
bool used[MAX_N];
double xx[MAX_N], yy[MAX_N], zz[MAX_N], rr[MAX_N];
double f(double in){
    return in * in;
}
double getdis(int i, int j){
    double dis = sqrt(f(xx[i] - xx[j]) + f(yy[i] - yy[j]) + f(zz[i] - zz[j])) - rr[i] - rr[j];
    if(dis < 0) return 0;
    else return dis;
}
void getcost(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cost[i][j] = 0;
                continue;
            }
            cost[i][j] = getdis(i, j);
        }
    }
}
double prim(){
    getcost();
    for(int i = 0; i < n; i++){
        mincost[i] = INF;
        used[i] = 0;
    }
    mincost[0] = 0;
    double res = 0;
    while(1){
        int v = -1;
        for(int u = 0; u < n; u++){
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        res += mincost[v];
        for(int u = 0; u < n; u++){
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
int main(){
    while(cin >> n){
        if(!n) break;
        for(int i = 0; i < n; i++){
            cin >> xx[i] >> yy[i] >> zz[i] >> rr[i];
        }
        printf("%.3f\n", prim());
    }
    return 0;
}
