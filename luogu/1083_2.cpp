// Author : Wqr_
// Time : 2019/9/3 21:11:33

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define nl (nc * 2)
#define nr (nc * 2 + 1)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll nmax = 1e6 + 50;

struct node {
  ll val, lazy, l, r;
} x[nmax * 4];
ll n, m;
vector<ll> ans;

void pushup(ll nc) {
  x[nc].val = min(x[nl].val, x[nr].val);
}

void pushdown(ll nc) {
  if (x[nc].lazy == 0) return;
  x[nl].lazy = x[nc].lazy;
  x[nr].lazy = x[nc].lazy;
  x[nl].val -= x[nl].lazy;
  x[nr].val -= x[nr].lazy;
  x[nc].lazy = 0;
}

void build(ll l, ll r, ll nc) {
  //cout << nc << "-" << l << "-" << r << endl;
  x[nc].l = l;
  x[nc].r = r;
  if (l == r) {
    scanf("%d", &x[nc].val);
    return;
  }
  ll mid = (l + r) / 2;
  build(l, mid, nl);
  build(mid + 1, r, nr);
  pushup(nc);
}

void upgrade(ll L, ll R, ll C, ll nc) {
  if (x[nc].r < L || x[nc].l > R) return;
  if (L <= x[nc].l && x[nc].r <= R) {
    x[nc].val -= C;
    x[nc].lazy = C;
    return;
  }
  pushdown(nc);
  ll mid = (x[nc].l + x[nc].r) / 2;
  if (L <= mid) upgrade(L, R, C, nl);
  if (R > mid) upgrade(L, R, C, nr);
  pushup(nc);
}

ll query(ll L, ll R, ll nc) {
  if (L <= x[nc].l && x[nc].r <= R) return x[nc].val;
  pushdown(nc);
  ll mid = (x[nc].l + x[nc].r) / 2;
  ll ret = INF;
  if (L <= mid) ret = min(ret, query(L, R, nl));
  if (R > mid) ret = min(ret, query(L, R, nr));
  return ret;
}

void test() {
  cin >> n;
  build(1, n, 1);
  char in;
  while (cin >> in) {
    if (in == 'Q') {
      cout << "query : " << endl;
      ll a, b;
      cin >> a >> b;
      cout << query(a, b, 1) << endl;
    } else if (in == 'U') {
      ll a, b, c;
      cin >> a >> b >> c;
      upgrade(a, b, c, 1);
    }
  }
}

void solve() {
  cin >> n >> m;
  build(1, n, 1);
  ll d, s, t;

  for (ll i = 1; i <= m; i++) {
    cin >> d >> s >> t;
    if (query(s, t, 1) < d) {
      ans.push_back(i);
      break;
    } else {
      upgrade(s, t, d, 1);
    }
  }
  if (!ans.size())
    cout << 0 << endl;
  else {
    cout << -1 << endl;
    cout << ans[0] << endl;
  }
}
int main() {
  iofuck;
  solve();
  return 0;
}
