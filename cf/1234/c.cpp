// Author : Wqr_
// Time : 19/10/01
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair
#define pb push_back
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
mt19937 mrand(random_device{}());
int rnd(int x){return mrand() % x;}
///////参数表///////
const ll mod = 1000000007;
///////////////////
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int nmax = 2e5 + 10;
int n;
bool vis[2][nmax];
string pp[2];
void dfs(int x, int y, char fang){
    //cout << x << "-" << y << "-" << fang << " ";
    if(vis[1][n]) return;
    if(vis[x][y]) return;
    vis[x][y] = 1;
    if(fang == 's' && x - 1 >= 0){
        if(pp[x - 1][y] == '0'){
            return ;
        }else{
            dfs(x - 1, y, 'y');
        }
    }
    if(fang == 'x' && x + 1 < 2){
        if (pp[x + 1][y] == '0') {
            return ;
        }else{
            dfs(x + 1, y, 'y');
        }
    }
    if(fang == 'y'){
        if(y + 1 != n){
            if (pp[x][y + 1] == '0') {
                dfs(x, y + 1, 'y');
            } else {
                if(x == 0) dfs(x, y + 1, 'x');
                else dfs(x, y + 1, 's');
            }
        }else{
            vis[x][y + 1] = 1;
            return ;
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        cin >> n;
        cin >> pp[0] >> pp[1];
        for (int i = 0; i < n; i++){
            if(pp[0][i] == '1' || pp[0][i] == '2') pp[0][i] = '0';
            else pp[0][i] = '1';
            if(pp[1][i] == '1' || pp[1][i] == '2') pp[1][i] = '0';
            else pp[1][i] = '1';
        }
        if(pp[0][0] == '0') dfs(0, 0, 'y');
        else dfs(0, 0, 'x');
        if(vis[1][n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}