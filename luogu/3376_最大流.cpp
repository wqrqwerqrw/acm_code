/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/11
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const int vmax = 100000 * 2 + 10;
const int nmax = 10000 + 10;
struct edge { int to, cap, rev; };
vector<edge> G[vmax];
bool used[vmax];
void add(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}
int n, m, s, t;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, w;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &w);
    }
    return 0;
}