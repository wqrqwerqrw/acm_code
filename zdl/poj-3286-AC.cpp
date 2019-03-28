/**********************************************************
    > File Name : poj-3286.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 23 20:23:04
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
struct road{
    int to;
    int cost;
};
typedef pair<int, int> P;
vector<road> G[1010];
int n, m, x;
int dback[1010];
int dgo[1010];

void dijgo(int f){
    priority_queue<P, vector<P>, greater<P> > q;
    fill(dgo, dgo + n, INF);
    dgo[f] = 0;
    q.push(P(0, f));
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int v = p.second;
        if(dgo[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            road e = G[v][i];
            if(dgo[e.to] > dgo[v] + e.cost){
                dgo[e.to] = dgo[v] + e.cost;
                q.push(P(dgo[e.to], e.to));
            }
        } 
    }
}

void dijback(int f){
    priority_queue<P, vector<P>, greater<P> > q;
    fill(dback, dback + n, INF);
    dback[f] = 0;
    q.push(P(0, f));
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int v = p.second;
        if(dback[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            road e = G[v][i];
            if(dback[e.to] > dback[v] + e.cost){
                dback[e.to] = dback[v] + e.cost;
                q.push(P(dback[e.to], e.to));
            }
        } 
    }
}

int main(){
    while(cin >> n >> m >> x){
        int maxn = -1;
        int a, b, c;
        for(int i = 0; i < m; i++){
            //cin >> a >> b >> c;
            scanf("%d %d %d", &a, &b, &c);
            road tmp;
            tmp.to = b - 1;
            tmp.cost = c;
            G[a - 1].push_back(tmp);
        }
        dijback(x - 1);
        for(int i = 0; i < n; i++){
            if(i == x - 1) continue;
            dijgo(i);
            if(dgo[x - 1] + dback[i] > maxn){
                maxn = dgo[x - 1] + dback[i];
            }
        }
        printf("%d\n", maxn);
    }
    return 0;
}
