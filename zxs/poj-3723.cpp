/*************************************************************************
    > File Name: poj-3723.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月04日 星期六 19时05分58秒
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
#define MAX_R 50100
#define MAX_V 20100
using namespace std;
int n, m, r, v;
struct edge{
    int a, b, c;
}es[MAX_R];
int par[MAX_V];
int ranc[MAX_V];
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        ranc[i] = 0;
    }
}
int find(int x){
    if(par[x] == x){
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
int same(int x, int y){
    return find(x) == find(y);
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ; 
    if(ranc[x] < ranc[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if(ranc[x] == ranc[y]) ranc[x]++;
    }
}
bool comp(const edge &e1, const edge &e2){
    return e1.c < e2.c;
}
int kruskal(){
    sort(es, es + r, comp);
    init(v);
    int res = 0;
    for(int i = 0; i < r; i++){
        edge e = es[i];
        if(!same(e.a, e.b)){
            unite(e.a, e.b);
            res += e.c;
        }
    }
    return res;
}
int main(){
    int num;
    cin >> num;
    while(num--){
        cin >> n >> m >> r;
        v = n + m;
        int a, b, c;
        for(int i = 0; i < r; i++){
            scanf("%d %d %d", &a, &b, &c);
            es[i] = (edge){a, b + n, -c};
        }
        printf("%d\n", 10000 * (n + m) + kruskal());
    }
    return 0;
}
