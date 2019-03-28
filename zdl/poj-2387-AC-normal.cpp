/**********************************************************
    > File Name : 2384.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 18 19:01:57
**********************************************************/
// 邻接矩阵+无优化 141ms
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
int map[1050][1050];
int t, n;
int d[1050];
bool used[1050];
void bell(int f){
    fill(d, d + n + 1, INF);
    memset(used, 0, sizeof(used));
    d[f] = 0;

    while(true){
        int v = -1;
        for(int u = 1;  u < n + 1; u++){
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        for(int u = 1; u < n + 1; u++){
            d[u] = min(d[u], d[v] + map[v][u]);
        }
    }
}
int main(){
    while(cin >> t >> n){
        int a, b, c;
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                map[i][j] = INF;
            }
        }
        for(int i = 0; i < t; i++){
            cin >> a >> b >> c;
            if(c < map[a][b]){
                map[a][b] = c;
                map[b][a] = c;
            }
        }
        for(int i = 0; i < n + 1; i++){
            map[i][i] = 0;
        }
        bell(1);
        cout << d[n] << endl;
    }
    return 0;
}