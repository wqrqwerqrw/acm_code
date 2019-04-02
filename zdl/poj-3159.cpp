/*************************************************************************
    > File Name: poj-3159.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月01日 星期一 19时46分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1<<28
using namespace std;
int n, m;
typedef pair<int, int> P;
struct road{
    int to, cost;
};
vector<road> G[30100];
int d[30100];
bool vis[30100];
void dij(int f){
    priority_queue<P, vector<P>, greater<P> > q;
    memset(vis, 0, sizeof(vis));
    //fill(d, d + n, INF);
    memset(d, 0, sizeof(d));
    //memset(d, -1, sizeof(d));
    q.push(P(0, f));
    d[f] = 0;
    while(!q.empty()){
        P p = q.top();
        q.pop();

        int v = p.second;
        
        if(d[v] > p.first || vis[v])
            continue;
        for(int i = 0; i < G[v].size(); i++){
            road tmp = G[v][i];
            if(d[tmp.to] < d[v] + tmp.cost){
                d[tmp.to] = d[v] + tmp.cost;
                q.push(P(d[tmp.to], tmp.to));
            }
            vis[v] = 1;
        }
    }
}
int main(){
    while(cin >> n >> m){
        for(int i = 0; i < m; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--;
            b--;
            road tmp;
            tmp.to = a;
            tmp.cost = c;
            G[b].push_back(tmp);
        }
        dij(n - 1);
        cout << d[0] << endl;
    }
    return 0;
}
