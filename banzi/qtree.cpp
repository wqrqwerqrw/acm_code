// Author : Wqr_
// Time : 19/09/16
// luogu 3384
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
#define nl (nc << 1)
#define nr (nc << 1 | 1)
using namespace std;
typedef long long ll;
const ll nmax = 1e5 + 10;
const ll nmax2 = 2e5 + 10;
ll n, m, r, mod;
ll w[nmax], wt[nmax];
/*******************向前星***************/
ll head[nmax], e = 0;
struct edge {
  ll next, to;
} eg[nmax2];
void add(ll u, ll v) {
  eg[e].to = v;
  eg[e].next = head[u];
  head[u] = e++;
}
/****************线段树****************/
struct sgt {
  struct node {
    ll val, l, r, lz;
    node() { lz = val = 0; }
    ll len() { return r - l + 1; }
    ll mid() { return (l + r) / 2; }
  } ns[nmax * 4];
  void pushup(ll nc) {
    ns[nc].val = (ns[nr].val + ns[nl].val) % mod;
  }
  void pushdown(ll nc) {
    node &lson = ns[nl];
    node &rson = ns[nr];
    node &cur = ns[nc];
    lson.lz += cur.lz;
    rson.lz += cur.lz;
    lson.val += cur.lz * lson.len();
    rson.val += cur.lz * rson.len();
    lson.val %= mod;
    rson.val %= mod;
    cur.lz = 0;
  }
  void pr(ll nc) {
    node &cur = ns[nc];
    if (cur.l == cur.r) {
      cout << cur.val << " ";
      return;
    }
    if (cur.lz) pushdown(nc);
    pr(nl);
    pr(nr);
  }
  void build(ll nc, ll l, ll r) {
    node &cur = ns[nc];
    cur.l = l;
    cur.r = r;
    if (l == r) {
      cur.val = wt[l] % mod;
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
      ret %= mod;
      return ret;
    }
    if (cur.lz) pushdown(nc);
    if (L <= cur.mid()) ret += query(nl, L, R);
    if (R > cur.mid()) ret += query(nr, L, R);
    ret %= mod;
    return ret;
  }
};
/**************树链穮分**************/
struct qtree {
  sgt tr;
  ll idcnt;
  qtree() { idcnt = 0; }
  struct node {
    ll deep, fa, id, top, son, siz;
  } ns[nmax];
  void init(ll root) {
    dfs1(root, 0, 1);
    dfs2(root, root);
    tr.build(1, 1, n);
  }
  void dfs1(ll x, ll f, ll deep) {
    node &cur = ns[x];
    cur.deep = deep;
    cur.fa = f;
    cur.siz = 1;
    ll maxson = -1;
    for (ll i = head[x]; i != -1; i = eg[i].next) {
      ll y = eg[i].to;
      if (y == f) continue;
      dfs1(y, x, deep + 1);
      cur.siz += ns[y].siz;
      if (ns[y].siz > maxson) {
        cur.son = y;
        maxson = ns[y].siz;
      }
    }
  }
  void dfs2(ll x, ll topf) {
    node &cur = ns[x];
    cur.id = ++idcnt;
    wt[cur.id] = w[x];
    cur.top = topf;
    if (!cur.son) return;
    dfs2(cur.son, topf);
    for (ll i = head[x]; i != -1; i = eg[i].next) {
      ll y = eg[i].to;
      if (y == cur.fa || y == cur.son) continue;
      dfs2(y, y);
    }
  }
  void add_by_way(ll x, ll y, ll C) {
    C %= mod;
    while (ns[x].top != ns[y].top) {
      if (ns[ns[x].top].deep < ns[ns[y].top].deep)
        swap(x, y);
      tr.update(1, ns[ns[x].top].id, ns[x].id, C);
      x = ns[ns[x].top].fa;
    }
    if (ns[x].deep > ns[y].deep) swap(x, y);
    tr.update(1, ns[x].id, ns[y].id, C);
  }
  ll que_by_way(ll x, ll y) {
    ll ans = 0;
    while (ns[x].top != ns[y].top) {
      if (ns[ns[x].top].deep < ns[ns[y].top].deep)
        swap(x, y);
      ans += tr.query(1, ns[ns[x].top].id, ns[x].id);
      ans %= mod;
      x = ns[ns[x].top].fa;
    }
    if (ns[x].deep > ns[y].deep) swap(x, y);
    ans += tr.query(1, ns[x].id, ns[y].id);
    ans %= mod;
    return ans;
  }
  void add_by_tree(ll x, ll C) {
    tr.update(1, ns[x].id, ns[x].id + ns[x].siz - 1, C);
  }
  ll que_by_tree(ll x) {
    return tr.query(1, ns[x].id, ns[x].id + ns[x].siz - 1) % mod;
  }
} qt;
int main() {
  iofuck;
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  memset(head, -1, sizeof(head));
  cin >> n >> m >> r >> mod;
  for (ll i = 1; i <= n; i++) {
    cin >> w[i];
  }
  ll u, v;
  for (ll i = 0; i < n - 1; i++) {
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  qt.init(r);
  ll x, y, z;
  ll com;
  for (int i = 0; i < m; i++) {
    cin >> com;
    if (com == 1) {
      cin >> x >> y >> z;
      qt.add_by_way(x, y, z);
    } else if (com == 2) {
      cin >> x >> y;
      cout << qt.que_by_way(x, y) << endl;
    } else if (com == 3) {
      cin >> x >> y;
      qt.add_by_tree(x, y);
    } else if (com == 4) {
      cin >> x;
      cout << qt.que_by_tree(x) << endl;
    }
  }
  return 0;
}