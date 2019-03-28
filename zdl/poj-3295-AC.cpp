/**********************************************************
    > File Name : poj-3295.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 24 17:15:01
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
int n, m, w;
int eee;
struct edge{
    int a, b, cost;
}es[10010];

int dis[10010];

bool bell(){
    fill(dis, dis + n, INF);
    dis[1] = 0;
    for(int i = 0; i < n - 1; i++){
        bool flag = false;
        for(int j = 0; j < eee; j++){
            if(dis[es[j].b] > dis[es[j].a] + es[j].cost){
                dis[es[j].b] = dis[es[j].a] + es[j].cost;
                flag = true;
            }
        }
        if(!flag) break;
    }
    for (int j = 0; j < eee; j++) {
        if (dis[es[j].b] > dis[es[j].a] + es[j].cost) {
            return true;
        }
    }
    return false;
}
int main(){
    int f;
    cin >> f;
    while(f--){
        eee = 0;
        cin >> n >> m >> w;
        int a, b, c;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            es[eee].a = a; 
            es[eee].b = b;
            es[eee++].cost = c;
            es[eee].a = b; 
            es[eee].b = a;
            es[eee++].cost = c;
        }
        for(int i = 0; i < w; i++){
            scanf("%d %d %d", &a, &b, &c);
            es[eee].a = a;
            es[eee].b = b;
            es[eee++].cost = -c; 
        }
        if(bell()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

