/*************************************************************************
    > File Name: hdu-1233.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月10日 星期五 15时19分59秒
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
using namespace std;
typedef long long ll;
int v, e;
int per[110], hi[110];
struct edge{
    int a, b, c;
}es[10010];
void init(int n){
    memset(per, 0, sizeof(per));
    memset(hi, 0, sizeof(hi));
    for(int i = 0; i < n; i++){
        per[i] = i;
        hi[i] = 0;
    }
}
int find(int x){
    if(per[x] == x) return x;
    else return per[x] = find(per[x]);
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(hi[x] < hi[y]){
        per[x] = y;
    }else{
        per[y] = x;
        if(hi[x] == hi[y]) hi[x]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
bool cmp(const edge &a, const edge &b){
    return a.c < b.c;
}
int kruskal(){
    sort(es, es + e, cmp);
    init(v);
    int res = 0;
    for(int i = 0; i < e; i++){
        edge e = es[i];
        if(!same(e.a, e.b)){
            unite(e.a, e.b);
            res += e.c;
        }
    }
    return res;
}
int main(){
    while(cin >> v){
        memset(es, 0, sizeof(es));
        if(!v) break;
        e = v * (v - 1) / 2;
        int a, b, c;
        for(int i = 0; i < e; i++){
            scanf("%d %d %d", &a, &b, &c);
            es[i].a = a;
            es[i].b = b;
            es[i].c = c;
        }
        cout << kruskal() << endl;
    }
    return 0;
}
