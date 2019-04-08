/*************************************************************************
    > File Name: poj-3255.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月08日 星期一 20时07分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int Nmax = 50100;
// 双向边 要 * 2
const int Mmax = 200100;
int n, m;
struct node{
    int next, to, w;
}eg[Mmax];
int head[Mmax];
long long int d1[Nmax];
long long int d2[Nmax];
typedef pair<int, int> P;
int cnt;
void add(int u, int v, int w){
    eg[cnt].w = w;
    eg[cnt].to = v;
    eg[cnt].next = head[u];
    head[u] = cnt++;
}

void dij(int s){
    priority_queue<P, vector<P>, greater<P> > q;
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    d1[s] = 0;
    //d2[s] = 0;
    q.push(P(0, s));
    while(!q.empty()){
        P p = q.top();
        q.pop();
        long long int v = p.second;
        if(d2[v] < p.first) continue;
        for(int i = head[v]; ~i; i = eg[i].next){
            node e = eg[i];
            long long int dd = e.w + p.first;
            if(d1[e.to] > dd){
                swap(d1[e.to], dd);
                q.push(P(d1[e.to], e.to));
            }
            if(d2[e.to] > dd && d1[e.to] < dd){
                d2[e.to] = dd;
                q.push(P(d2[e.to], e.to));
            }
        }
    }
}

int main(){
    while(cin >> n >> m){
        cnt = 0;
        memset(head, -1, sizeof(head));
        int a, b, c;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            add(b-1, a-1, c);
            add(a-1, b-1, c);
        }
        if(m == 1){
            cout << 3 * c << endl;
            continue;
        }
        dij(0);
        cout << d2[n - 1] << endl;
    }
    return 0;
}
