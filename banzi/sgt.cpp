// Author : Wqr_
// Time : 19/09/16
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
#define nl (nc << 1)
#define nr (nc << 1 | 1)
using namespace std;
typedef long long ll;
const ll nmax = 1e5 + 10;
const ll nmax2 = 2e5 + 10;
ll a[nmax];
struct sgt {
    struct node {
        ll val, l, r, lz;
        node() { lz = val = 0;}
        ll len() { return r - l + 1; }
        ll mid() { return (l + r) / 2; }
    } ns[nmax * 4];
    void pushup(ll nc) {
        ns[nc].val = ns[nr].val + ns[nl].val;
    }
    void pushdown(ll nc) {
        node &lson = ns[nl];
        node &rson = ns[nr];
        node &cur = ns[nc];
        lson.lz += cur.lz;
        rson.lz += cur.lz;
        lson.val += cur.lz * lson.len();
        rson.val += cur.lz * rson.len();
        cur.lz = 0;
    }
    // 调试用
    void pr(ll nc){
        node &cur = ns[nc];
        if(cur.l == cur.r){
            cout << cur.val << " ";
            return ;
        }
        if(cur.lz) pushdown(nc);
        pr(nl);
        pr(nr);
    }
    void build(ll nc, ll l, ll r) {
        node &cur = ns[nc];
        cur.l = l;
        cur.r = r;
        if (l == r) {
            cur.val = a[l];
            return;
        }
        build(nl, l, cur.mid());
        build(nr, cur.mid() + 1, r);
        pushup(nc);
    }
    void update(ll nc, ll L, ll R, ll C) {
        node &cur = ns[nc];
        if (L <= cur.l && cur.r <= R) {
            cur.lz += C;
            cur.val += C * cur.len();
            return;
        }
        if (cur.lz) pushdown(nc);
        if (L <= cur.mid()) update(nl, L, R, C);
        if (R > cur.mid()) update(nr, L, R, C);
        pushup(nc);
    }
    ll query(ll nc, ll L, ll R) {
        node &cur = ns[nc];
        ll ret = 0;
        if (L <= cur.l && cur.r <= R) {
            ret += cur.val;
            return ret;
        }
        if (cur.lz) pushdown(nc);
        if (L <= cur.mid()) ret += query(nl, L, R);
        if (R > cur.mid()) ret += query(nr, L, R);
        return ret;
    }
};
int main() {
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    return 0;
}