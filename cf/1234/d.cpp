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
#define nl (nc << 1)
#define nr (nc << 1 | 1)
///////////////////
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
string in;
const int nmax = 1e5 + 10;
int mar(int a, int b){
    return (a | b);
}
int getans(int in){

}
struct stg{
    struct node{
        int l, int r, int v;
        node{v = 0;}
        int mid() { return (l + r) / 2; }
    }ns[nmax * 4];
    void pushup(int nc){
        int vl = ns[nc * 2].v;
        int vr = ns[nc * 2 + 1].v;
        ns[nc].v = (vl | vr);
    }
    void build(int nc, int l, int r, char in){
        node& cur = ns[nc];
        cur.l = l;
        cur.r = r;
        if(l == r){
            cur.v = (1 << in);
            return ;
        }
        build(nl, l, cur.mid());
        build(nr, cur.mid() + 1, r);
        pushup(nc);
    }
    int qu(int nc, int L, int R){
        node& cur = ns[nc];
        int ret = 0;
        if (L <= cur.l && cur.r <= R) {
            return cur.v;
        }
        if(L <= cur.mid()) ret = mar(ret, qu(nl, L, R));
        if(R > cur.mid()) ret = mar(ret, qu(nr, L, R));
        return ret;
    }
    int getans(int L, int R){
        int ans = qu(1, L, R);
    }
    void update(int nc, int L, char in){
        node& cur = ns[nc];
        if(cur.l == cur.r){
            cur.v == (1 << in);
            return ;
        }
        if(L <= cur.mid()) update(nl, L, C);
        if(L > cur.mid()) update(nr, L, C);
        pushup(nc);
    }
}tr;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> in;
    }
    return 0;
}