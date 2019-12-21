/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/07
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
const ll nmax = 1e5 + 5;
const ll mod = 1e9 + 7;
struct node {
    ll x, y, v;
}maxNode[nmax], minNode[nmax];
ll n, e;
ll a[nmax];
int fa[nmax];
int cnt[nmax];
void init(){
    for(int i = 0; i < n; i++){
        fa[i] = i;
        cnt[i] = 1;
    }
}
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void uni(int x, int y){
    fa[x] = y;
    cnt[y] += cnt[x];
}
int main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        e = n - 1;
        for(int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        for(int i = 0; i < e; i++){
            cin >> x >> y;
            x--;
            y--;
            maxNode[i] = node{x, y, max(a[x], a[y])};
            minNode[i] = node{x, y, min(a[x], a[y])};
        }
        //maxnode从小到大排列
        sort(maxNode, maxNode + e, [](node& a, node& b){
            return a.v < b.v;
        });
        // minnode从大到小排列
        sort(minNode, minNode + e, [](node& a, node& b){
            return a.v > b.v;
        });
        init();
        ll maxsum = 0;
        for(int i = 0; i < e; i++){
            int curx = find(maxNode[i].x);
            int cury = find(maxNode[i].y);
            maxsum = (maxNode[i].v * cnt[curx] % mod * cnt[cury] % mod + maxsum) % mod;
            uni(curx, cury);
        }
        init();
        ll minsum = 0;
        for(int i = 0; i < e; i++){
            int curx = find(minNode[i].x);
            int cury = find(minNode[i].y);
            minsum = (minNode[i].v * cnt[curx] % mod * cnt[cury] % mod + minsum) % mod;
            uni(curx, cury);
        }
        ll ans = (maxsum - minsum + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}