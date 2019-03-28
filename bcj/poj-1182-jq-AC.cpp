/**********************************************************
    > File Name : poj-1182-jq.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 22 09:57:18
**********************************************************/
// 282ms
#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
struct nodep{
    int per;
    int high;
    //0=>同类 1=>被父节点吃 2=>吃父节点
    int rel;
}node[50100];
int n, k;
int D[100010];
int X[100010];
int Y[100010];

void init(){
    for(int i = 0 ; i < n; i++){
        node[i].per = i;
        node[i].rel = 0;
    }
}


int find(int a){
    if(node[a].per == a) return a;
    else{
        int tmp = node[a].per;
        node[a].per = find(node[a].per);
        node[a].rel = (node[a].rel + node[tmp].rel + 3) % 3;
        return node[a].per;
    }
}

void uni(int a, int b, int d){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return ;
    /*
    if(node[pa].high > node[pb].high){
        node[pb].per = pa;
        node[pb].rel = (d + node[a].rel - node[b].rel + 3) % 3;
    }else if(node[a].high < node[b].high){
        node[a].per = b;
        node[pa].rel = (d + node[b].rel - node[a].rel + 3) % 3;
    }else{
        node[a].per = b;
        node[pa].rel = (d + node[b].rel - node[a].rel + 3) % 3;
        node[pb].high++;
    }
    合并树 注意：被 x 吃，所以以 x 的根为父
    也就是说, 不能按照白书上介绍的那样进行压缩操作
    */

    node[pb].per = pa;
    node[pb].rel = (d + node[a].rel - node[b].rel + 3) % 3;
}

bool same(int a, int b){
    return find(a) == find(b);
}

int getrel(int a, int b){
    // 所求为 a => b 的关系
    find(a);
    find(b);
    return (node[a].rel - node[b].rel + 3) % 3;
}
void solve(){
    init();
    int ans = 0;
    for(int i = 0; i < k; i++){
        int d = D[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;
        if(d == 2 && x == y){
            ans++;
            continue;
        }
        if(x < 0 || x >= n || y < 0 || y >= n){
            ans++;
            continue;
        }

        if(same(x, y)){
            if(d == 1 && getrel(x, y) != 0) ans++;
            if(d == 2 && getrel(x, y) != 2) ans++; 
        }
        uni(x, y, d - 1);
    }
    printf("%d", ans);
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", D + i, X + i, Y + i);
    }
    solve();
    return 0;
}