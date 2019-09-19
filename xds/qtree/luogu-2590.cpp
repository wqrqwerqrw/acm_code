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
struct edge {
    int next, to;
}eg[nmax * 2];
void add(int u, int v){
    eg[e].to = v;
    eg[e].next = head[u];
    head[u] = e++;
}
struct sgt{
    struct node{
        int vmax, vsum, l, r;
        node(){vmax = vsum = 0;}
        int len() {return l - r + 1;}
        int mid() {return (l + r) / 2;}
    }ns[nmax * 4];
    void pushup(int nc){
        ns[nc].vmax = max(ns[nl].vmax, ns[nr].vmax);
        ns[nc].vsum = ns[nl].vsum + ns[nr].vsum;
    }
    void pr(int nc){
        node &cur = ns[nc];
        if(cur.l == cur.r){
            cout << cur.vmax << " ";
            return ;
        }
        pr(nl);
        pr(nr);
    }
    void build(int nc, int l, int r){
        node &cur = ns[nc];
        cur.l = l;
        cur.r = r;
        if(l == r){
            cur.vmax = cur.vsum = wt[l];
            return ;
        }
        build(nl, l, cur.mid());
        build(nr, cur.mid() + 1, r);
        pushup(nc);
    }
    void update(int nc, int L, int C){
        node &cur = ns[nc];
        if(cur.l == cur.r){
            cur.vsum = cur.vmax = C;
            return ;
        }
        if(L <= cur.mid()) update(nl, L, C);
        if(L > cur.mid()) update(nr, L, C);
        pushup(nc);
    }
    int query_max(int nc, int L, int R){
        node &cur = ns[nc];
        int ret = -INF;
        if(L <= cur.l && cur.r <= R){
            ret = max(ret, cur.vmax);
            return ret;
        }
        if(L <= cur.mid()) ret = max(ret, query_max(nl, L, R));
        if(R > cur.mid()) ret = max(ret, query_max(nr, L, R));
        return ret;
    }
    int query_sum(int nc, int L, int R){
        node &cur = ns[nc];
        int ret = 0;
        if(L <= cur.l && cur.r <= R){
            ret += cur.vsum;
            return ret;
        }
        if(L <= cur.mid()) ret += query_sum(nl, L, R);
        if(R > cur.mid()) ret += query_sum(nr, L, R);
        return ret;
    }
};
struct qtree{
    struct node{
        int deep, fa, id, top, son, siz;
    } ns[nmax];
    sgt sss;
    int idcnt;
    qtree() {
        idcnt = 0;
    }
    void init(){
        dfs1(1, 0, 1);
        dfs2(1, 1);
        sss.build(1, 1, n);
    }
    void dfs1(int x, int f, int deep) {
        node &cur = ns[x];
        cur.deep = deep;
        cur.fa = f;
        cur.siz = 1;
        int maxson = -1;
        for (int i = head[x]; i != -1; i = eg[i].next) {
            int y = eg[i].to;
            if (y == f) continue;
            dfs1(y, x, deep + 1);
            cur.siz += ns[y].siz;
            if (ns[y].siz > maxson) {
                cur.son = y;
                maxson = ns[y].siz;
            }
        }
    }
    void dfs2(int x, int topf) {
        node &cur = ns[x];
        cur.id = ++idcnt;
        wt[cur.id] = w[x];
        cur.top = topf;
        if (!cur.son) return;
        dfs2(cur.son, topf);
        for (int i = head[x]; i != -1; i = eg[i].next) {
            int y = eg[i].to;
            if (y == cur.fa || y == cur.son) continue;
            dfs2(y, y);
        }
    }
    void change(int nc, int C){
        sss.update(1, ns[nc].id, C);
    }
    int quemax(int x, int y){
        int ans = -INF;
        while (ns[x].top != ns[y].top) {
            if (ns[ns[x].top].deep < ns[ns[y].top].deep)
                swap(x, y);
            ans = max(ans, sss.query_max(1, ns[ns[x].top].id, ns[x].id));
            x = ns[ns[x].top].fa;
        }
        if(ns[x].deep > ns[y].deep) swap(x, y);
        ans = max(ans, sss.query_max(1, ns[x].id, ns[y].id));
        return ans;
    }
    int quesum(int x, int y){
        int ans = 0;
        while (ns[x].top != ns[y].top) {
            if (ns[ns[x].top].deep < ns[ns[y].top].deep)
                swap(x, y);
            ans += sss.query_sum(1, ns[ns[x].top].id, ns[x].id);
            x = ns[ns[x].top].fa;
        }
        if(ns[x].deep > ns[y].deep) swap(x, y);
        ans += sss.query_sum(1, ns[x].id, ns[y].id);
        return ans;
    }
    void test(){
        sss.pr(1);
        cout << endl;
    }
}qt;
int main(){
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    memset(head, -1, sizeof(head));
    cin >> n;
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    qt.init();
    //qt.test();
    cin >> q;
    string ope;
    int x, y;
    while(q--){
        cin >> ope >> x >> y;
        if(ope[1] == 'H') qt.change(x, y);
        if(ope[1] == 'M') cout << qt.quemax(x, y) << endl;
        if(ope[1] == 'S') cout << qt.quesum(x, y) << endl;
    }
    return 0;
}