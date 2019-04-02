/*************************************************************************
    > File Name: poj-3159-per.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月02日 星期二 19时52分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1<<28
using namespace std;
typedef pair<int, int> P;
int n, m;
const int Nmax = 30010;
const int Mmax = 150100;
int cnt = 0;
struct node{
    int next, to, w;
}eg[Mmax];
int d[Mmax], head[Mmax], vis[Mmax];
void add(int u, int v, int w){
    eg[cnt].w = w;
    eg[cnt].to = v;
    eg[cnt].next = head[u];
    head[u] = cnt++;
}

void dij(int s){
    priority_queue<P, vector<P>, greater<P> > q;
    fill(d, d + n, INF);
    d[s] = 0;
    q.push(P(0, s));
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = head[v]; ~i; i=eg[i].next){
            node e = eg[i];
            if(d[e.to] > e.w + d[v]){
                d[e.to] = e.w + d[v];
                q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    while(cin >> n >> m){
        memset(head, -1, sizeof(head));
        int a, b, c;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            add(b-1, a-1, c);
        }
        dij(n-1);
        cout << d[0] << endl;
    }
    return 0;
}
