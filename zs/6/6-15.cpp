// Author : Wqr_
// Time : 2019年07月18日 星期四 20时48分36秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int maxn = 200+5;
bool G[maxn][maxn];
int c[maxn];
int topo[maxn], t;
int n;
bool dfs(int u){
    c[u] = -1;
    for(int v = 0; v < n; v++) if(G[u][v]){
        if(c[v] < 0) return false;
        else if(!c[v] && !dfs(v)) return false;
    }
    c[u] = 1;
    topo[--t] = u;
    return true;
}
bool toposort(){
    t = n;
    memset(c, 0, sizeof(c));
    for(int u = 0; u < n; u++) if(!c[u]){
        if(!dfs(u))  return false;
    }
    return true;
}
int main(){
    iofuck;
    int a, b;
    n = 0;
    while(cin >> a >> b){
        n++;
        if(a == 0 && b == 0) break;
        G[b][a] = 1;
    }
    toposort();
    for(int i = 0; i < n - 1; i++){
        cout << topo[i] << " ";
    }
    return 0;
}
