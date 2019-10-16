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
const int nmax = 100, emax = 100;
ll head[nmax], e = 0;
struct edge {
    int next, to, val;
} eg[emax];
void add(int u, int v, int c) {
    eg[e].val = c;
    eg[e].to = v;
    eg[e].next = head[u];
    head[u] = e++;
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    
    return 0;
}