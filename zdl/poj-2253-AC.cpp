/**********************************************************
    > File Name : 2253.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 19 18:47:31
**********************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#define INF 1<<28
using namespace std;
typedef pair<int , int> point;
point ps[250];
int n;
double d[250];
bool used[250];
double map[250][250];
void getdis(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                map[i][j] = 0;
                continue;
            }else{
                double dis;
                dis = sqrt(pow((double)(ps[i].first - ps[j].first), 2) + pow((double)(ps[i].second - ps[j].second), 2));
                map[i][j] = dis;
                map[j][i] = dis;
            }
        }
    }
}
void diji(int f){
    fill(d, d + n, INF);
    memset(used, 0, sizeof(used));
    d[f] = 0;
    while(true){
        int v = -1;
        double mind = INF;
        for(int u = 0; u < n; u++){
            if(!used[u] && (v == - 1 || d[u] < mind)){
                v = u;
                mind = d[u];
            }
        }
        if(v == -1) break;
        used[v] = 1;
        for(int u = 0; u < n; u++){
            // 更新的是f号石头到u号石头最长边的最小值
            d[u] = min(d[u], max(d[v],map[v][u]));
        }
    }
}
int main(){
    int kase = 0;
    while(cin >> n){
        if(n == 0) break;
        int a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            ps[i].first = a;
            ps[i].second = b;
        }
        getdis();
        diji(0);
        printf("Scenario #%d\n", ++kase);
        printf("Frog Distance = %.3f", d[1]);
        printf("\n");
        printf("\n");
    }
    return 0;
}