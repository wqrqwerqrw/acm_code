// Author : Wqr_
// Time : 19/09/17
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define nl (nc << 1)
#define nr (nc << 1 | 1)
using namespace std;
typedef long long ll;
const int nmax = 3e5 + 50;
int n, q, head[nmax], e = 0, w[nmax], wt[nmax];
struct sgt{
    struct node{
        ll vmax, vsum, l, r;
        node(){vmax = vsum = 0;}
        ll len() {return l - r + 1;}
        ll mid() {return (l + r) / 2;}
    }ns[nmax * 4];
    void pushup(ll nc){
        ns[nc].vmax = max(ns[nl].vmax, ns[nr].vmax);
        ns[nc].vsum = ns[nl].vsum + ns[nr].vsum;
    }
    void pr(ll nc){
        node &cur = ns[nc];
        if(cur.l == cur.r){
            cout << cur.vmax << " ";
            return ;
        }
        pr(nl);
        pr(nr);
    }
    void build(ll nc, ll l, ll r){
        node &cur = ns[nc];
        cur.l = l;
        cur.r = r;
        if(l == r){
            int in;
            cin >> in;
            cur.vmax = cur.vsum = in;
            return ;
        }
        build(nl, l, cur.mid());
        build(nr, cur.mid() + 1, r);
        pushup(nc);
    }
    void update(ll nc, ll L, ll C){
        node &cur = ns[nc];
        if(cur.l == cur.r){
            cur.vsum = cur.vmax = C;
            return ;
        }
        if(L <= cur.mid()) update(nl, L, C);
        if(L > cur.mid()) update(nr, L, C);
        pushup(nc);
    }
    ll query_max(ll nc, ll L, ll R){
        node &cur = ns[nc];
        ll ret = 0;
        if(L <= cur.l && cur.r <= R){
            ret = max(ret, cur.vmax);
            return ret;
        }
        if(L <= cur.mid()) ret = max(ret, query_max(nl, L, R));
        if(R > cur.mid()) ret = max(ret, query_max(nr, L, R));
        return ret;
    }
    ll query_sum(ll nc, ll L, ll R){
        node &cur = ns[nc];
        ll ret = 0;
        if(L <= cur.l && cur.r <= R){
            ret = cur.vsum;
            return ret;
        }
        if(L <= cur.mid()) ret += query_sum(nl, L, R);
        if(R > cur.mid()) ret += query_sum(nr, L, R);
        return ret;
    }
}sgt;
int main(){
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    cin >> n;
    sgt.build(1, 1, n);
    cout << sgt.query_sum(1, 1, n) << endl;
    sgt.pr(1);
    cout << endl;
    sgt.update(1, 7, 100);
    sgt.pr(1);
    cout << endl;
    cout << sgt.query_max(1, 1, n) << endl;
    cout << sgt.query_sum(1, 1, n) << endl;
    return 0;
}