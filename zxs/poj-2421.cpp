/*************************************************************************
    > File Name: poj-2421.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月05日 星期日 18时30分49秒
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
#define INF 0x3f3f3f3f
using namespace std;
int n;
int cost[MAX_N][MAX_N];
int mincost[MAX_N];
bool used[MAX_N];
int prim(){
    memset(mincost, 0x3f, sizeof(mincost));
    memset(used, 0, sizeof(used));
    mincost[0] = 0;
    int res = 0;
    while(1){
        int v = -1;
        for(int u = 0; u < n; u++){
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if(v == -1) break;
        used[v] = 1; 
        res += mincost[v];
        for(int u = 0; u < n; u++){
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
int main(){
    while(cin >> n){
        int in;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &in);
                cost[i][j] = in;
            }
        }
        int q;
        int a, b;
        cin >> q;
        for(int i = 0; i < q; i++){
            scanf("%d %d", &a, &b);
            --a, --b;
            cost[a][b] = cost[b][a] = 0;
        }
        cout << prim() << endl;
    }
    return 0;
}
