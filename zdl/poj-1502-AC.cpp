/**********************************************************
    > File Name : poj-1502.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 24 19:50:50
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
int map[510][510];
int n;
int d[201];
bool used[201];
void dij(int f){
    fill(d, d + n, INF);
    memset(used, 0, sizeof(used));
    d[f] = 0;
    while(true){
        int v = -1;
        for(int u = 0; u < n; u++){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        for(int u = 0; u < n; u++){
            d[u] = min(d[u], d[v] + map[v][u]);
        }
    }
}
int main(){
    while(cin >> n){
        char in[20];
        int l = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < l; j++){
                if(i == j){
                    map[i][j] == 0;
                }else{
                    //cin >> in;
                    scanf("%s", in);
                    if(in[0] == 'x') map[i][j] = map[j][i] = INF;
                    // atoi 方便的东西
                    else map[i][j] = map[j][i] = atoi(in);
                }
            }
            l++;
        }
        dij(0);
        int maxn = -1;
        for(int i = 1; i < n; i++){
            if(d[i] > maxn) maxn = d[i];
        }
        printf("%d\n", maxn);
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
    return 0;
}
