// Wqr_
// Time : 20/02/04
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1e5 + 7;
int sum[N << 2], lazy[N << 2], l[N << 2], r[N << 2];
#define ls(rt) rt << 1
#define rs(rt) rt << 1 | 1
void pushup(int rt) { sum[rt] = sum[ls(rt)] + sum[rs(rt)]; }
void pushdown(int rt) {
  if (!lazy[rt]) return;
  lazy[ls(rt)] += lazy[rt];
  lazy[rs(rt)] += lazy[rt];
  sum[ls(rt)] += lazy[rt] * (r[ls(rt)] - l[ls(rt)] + 1);
  sum[rs(rt)] += lazy[rt] * (r[rs(rt)] - l[rs(rt)] + 1);
  lazy[rt] = 0;
}
void build(int L, int R, int rt) {
  l[rt] = L;
  r[rt] = R;
  if (L == R) return;
  int mid = (L + R) >> 1;
  build(L, mid, ls(rt));
  build(mid + 1, R, rs(rt));
  pushup(rt);
}
void update(int L, int R, int rt, int x) {
  if (L > r[rt] || l[rt] > R) return;
  if (L <= l[rt] && r[rt] <= R) {
    lazy[rt] += x;
    sum[rt] += x * (r[rt] - l[rt] + 1);
    return;
  }
  pushdown(rt);
  update(L, R, ls(rt), x);
  update(L, R, rs(rt), x);
  pushup(rt);
}
int query(int L, int R, int rt) {
  if (L > r[rt] || l[rt] > R) return 0;
  if (L <= l[rt] && r[rt] <= R) return sum[rt];
  pushdown(rt);
  return query(L, R, ls(rt)) + query(L, R, rs(rt));
}

struct Node {
  int x, y;
  char fa;
};
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    char ch;
    int x, y, n, m, k;
    cin >> n >> m >> k;
    vector<Node> e;
    vector<int> al;
    for (int i = 0; i < k; i++) {
      cin >> x >> y >> ch;
      e.push_back({x, y, ch});
      al.push_back(y);
    }
    sort(al.begin(), al.end());
    auto aend = unique(al.begin(), al.end());
    for (auto& i: e) i.y = lower_bound(al.begin(), aend, i.y) - al.begin() + 1;
    sort(e.begin(), e.end(), [](const Node& a, const Node& b) {
      return a.x < b.x;
    });
    int cnt = aend - al.begin() + 1;
    memset(sum, 0, sizeof(sum));
    memset(lazy, 0, sizeof(lazy));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    build(1, cnt, 1);
    ll ans = 1;
    for (int i = 0; i < k; i++) {
      y = e[i].y;
      if (e[i].fa == 'D') update(1, y, 1, 1);
      if (e[i].fa == 'U') update(y, cnt, 1, 1);
      if (e[i].fa == 'L') ans += query(y, y, 1);
    }
    memset(sum, 0, sizeof(sum));
    memset(lazy, 0, sizeof(lazy));
    for (int i = k - 1; i >= 0; i--) {
      y = e[i].y;
      if (e[i].fa == 'D') update(1, y, 1, 1);
      if (e[i].fa == 'U') update(y, cnt, 1, 1);
      if (e[i].fa == 'R') ans += query(y, y, 1);
    }
    cout << ans << "\n";
  }
  return 0;
}