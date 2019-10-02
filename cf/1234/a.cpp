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
int q, n;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> q;
    while(q--){
        cin >> n;
        ll ans = 0;
        int in;
        for(int i = 0; i < n; i++){
            cin >> in;
            ans += in;
        }

        if(ans / n * n != ans){
            cout << (ans / n + 1) << endl;
        }else{
            cout << ans / n << endl;
        }
    }
    return 0;
}