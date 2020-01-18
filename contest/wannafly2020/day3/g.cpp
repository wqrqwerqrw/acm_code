// Wqr_
// Time : 20/01/16
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define ttt cerr<<"test"<<endl
typedef long long ll;
using namespace std;
#define int long long
const int N = 5e5 + 50;
struct edge {
    int v, w;
};
vector<edge> G[N];
bool ifk[N];
int f[N], fk[N], dis2k[N], disk2k[N][2];
int n, k;
void build_tree(int in){
    for(auto e : G[in]){
        if(e.v != f[in]){
            f[e.v] = in;
            build_tree(e.v);
        }
    }
}
void build_K_tree(){
    for(int i = 1; i <= n; i++){
        if(ifk[i]){
            int tmp = i;
            while(!ifk[f[tmp]] && f[tmp]){
                tmp = f[tmp];
                ifk[tmp] = 1;
                k++;
            }
        }
    }
}
int sizek;
void getsizek(int in){
    for(auto e : G[in]){
        if(e.v != f[in] && ifk[e.v]){
            sizek += e.w;
            getsizek(e.v);
        }
    }
}
void getdis2k(int in, int lastk){
    if (ifk[in]) dis2k[in] = 0, lastk = in;
    fk[in] = lastk;
    for(auto e : G[in]){
        if(e.v != f[in]){
            dis2k[e.v] = dis2k[in] + e.w;
            getdis2k(e.v, lastk);
        }
    }
}
int maxdisk2k, maxpoint, vis[N];
void getdisk2k(int in, int mark){
    vis[in] = 1;
    for(auto e : G[in]){
        if(!vis[e.v] && ifk[e.v]){
            disk2k[e.v][mark] = disk2k[in][mark] + e.w;
            if(disk2k[e.v][mark] > maxdisk2k){
                maxdisk2k = disk2k[e.v][mark];
                maxpoint = e.v;
            }
            getdisk2k(e.v, mark);
        }
    }
}
signed main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    int u, v, w;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for(int i = 0; i < k; i++){
        cin >> u;
        ifk[u] = 1;
    }
    build_tree(u);
    build_K_tree();
    getsizek(u);
    getdis2k(u, u);
    int d1, d2;

    maxdisk2k = maxpoint = 0;
    memset(vis, 0, sizeof(vis));
    getdisk2k(u, 0);
    d1 = maxpoint;

    maxdisk2k = maxpoint = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        disk2k[i][0] = 0;
    }
    getdisk2k(d1, 0);
    d2 = maxpoint;

    maxdisk2k = maxpoint = 0;
    memset(vis, 0, sizeof(vis));
    getdisk2k(d2, 1);

    // check();
    for(int i = 1; i <= n; i++){
        // cerr << i << ddd(dis2k[i]) << ddd(sizek) << ddd(max(disk2k[fk[i]][0], disk2k[fk[i]][1])) << endl;
        int ans = dis2k[i] + sizek * 2 - max(disk2k[fk[i]][0], disk2k[fk[i]][1]);
        cout << ans << endl;
    }
    return 0;
}