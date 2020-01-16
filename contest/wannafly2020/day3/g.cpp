/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/14
#include <bits/stdc++.h>
#define fi first
#define se second
// #define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
map<int, int> g[N]; 
map<int, int> nofk;
set<int> ks;
stack<int> st;
int ans[N];
int dis[N];
int fa[N];
int ti[N], curti;
map<int, bool> visk;
bool first = 1, stti = 0, enti = 0;
void dfs1(int in){
    for(auto i : g[in]) if(i.fi != fa[in]){
        fa[i.fi] = in;
        dfs1(i.fi);
    }
}
void dfs2ans(int in){
    visk[in]++;
    ti[in] = curti++;
    for(auto i : g[in]) if(i.fi != fa[in]){
        dfs2ans(i.fi);
    }
    while(5)
    ti[in] = curti++;
    visk[in]++;
}
int n, k;
int32_t main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    int u, v, w;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }
    for(int i = 0; i < k; i++){
        cin >> u;
        ks.insert(u);
    }
    dfs1(*ks.begin());
    dfs2ans(*ks.begin());
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}