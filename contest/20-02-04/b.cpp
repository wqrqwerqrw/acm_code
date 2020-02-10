#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
struct rbtree : tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define RI register int
#define int long long
#define endl '\n'
#define pb push_back
#define lowb lower_bound
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mem0(a) memset((a), 0, sizeof(a))
#define mem(a, b) memset((a), (b), sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;

const int N = 2e5 + 10;

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
} e[N];

int al[N * 3], cnt = 1;
bool cmp1(Node A, Node B) {
  return A.x < B.x;
}
int find(int x) {
  return lowb(al + 1, al + 1 + cnt, x) - al;
}
int32_t main() {
  IOS;
  IN;
  int _;
  cin >> _;
  while (_--) {
    mem0(sum), mem0(lazy), mem0(l), mem0(r);
    cnt = 0;
    char ch;
    int x, y, n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
      cin >> x >> y >> ch;
      e[i].x = x, e[i].y = y, e[i].fa = ch;
      al[++cnt] = x, al[++cnt] = y;
    }
    sort(al, al + cnt);
    cnt = unique(al + 1, al + 1 + cnt) - al;
    build(1, cnt, 1);
    ll ans = 0;
    sort(e + 1, e + 1 + k, cmp1);
    for (int i = 1; i <= k; i++) {
      x = find(e[i].x), y = find(e[i].y);
      e[i].x = x, e[i].y = y;
      if (e[i].fa == 'D') update(1, y, 1, 1);
      if (e[i].fa == 'U') update(y, cnt, 1, 1);
      if (e[i].fa == 'L') ans += query(y, y, 1);
    }
    ////////
    mem0(sum), mem0(lazy);
    for (int i = k; i >= 1; i--) {
      x = e[i].x, y = e[i].y;
      if (e[i].fa == 'D') update(1, y, 1, 1);
      if (e[i].fa == 'U') update(y, cnt, 1, 1);
      if (e[i].fa == 'R') ans += query(y, y, 1);
    }
    cout << ans + 1 << endl;
  }
  return 0;
}