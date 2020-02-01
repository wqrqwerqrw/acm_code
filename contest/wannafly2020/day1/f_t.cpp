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
#define bbb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define RI register int
#define endl '\n'
#define pb push_back
#define lowb lower_bound
#define eb emplace_back
#define fi first
#define int long long
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
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
int a[N], b[N], ta, n, m, k;
;
int check(int tar) {
  int c1 = 0, c2 = 0;  //c1小于的个数, c2自身个数
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      if (tar > 0) {
        c1 += m;
      }
      if (tar == 0) {
        c2 += m;
      }
      continue;
    }
    int tp = tar / a[i];
    if (a[i] >= 0) {
      if (tp * a[i] != tar) {
        c1 += upper_bound(b + 1, b + 1 + m, tp) - b - 1;
      } else {
        int z = upper_bound(b + 1, b + 1 + m, tp - 1) - b - 1;
        int tt = upper_bound(b + 1, b + 1 + m, tp) - b - 1;
        c1 += z;
        c2 += tt - z;
      }
    } else {
      if (tp * a[i] != tar) {
        c1 += m - (upper_bound(b + 1, b + 1 + m, tp) - b - 1);
      } else {
        int z = m - (upper_bound(b + 1, b + 1 + m, tp) - b - 1);
        int tt = m - (upper_bound(b + 1, b + 1 + m, tp - 1) - b - 1);
        // cerr << debug(z) << debug(tt) << endl;
        c1 += z;
        c2 += tt - z;
      }
    }
  }
  if (c1 < ta && c1 + c2 >= ta && c2) return 0;
  if (c1 + c2 < ta) return -1;
  return 1;
}

int32_t main() {
  IOS;
  IN;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + 1 + m);
  int L = -inf;
  int R = inf;
  ta = n * m - k + 1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    int tp = check(mid);
    // cerr<<bbb(L)<<bbb(mid)<<bbb(R)<<endl;
    if (tp == 0) {
      cout << mid;
      return 0;
    }
    if (tp == 1)
      R = mid - 1;
    else
      L = mid + 1;
  }
  // cout << L;
  return 0;
}