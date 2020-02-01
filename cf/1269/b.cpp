#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
struct rbtree : tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
#define IN freopen("in.txt", "r", stdin);
#define int long long
//#define endl '\n'
#define mp make_pair
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

const int N = 2e3 + 10;
int a[N], b[N];
map<int, int> msk;

int32_t main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  IOS;
  //cout << inf << endl;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    msk[b[i]]++;
  }
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    int k = (b[i] - a[1] + m) % m;
    bool f = 0;
    map<int, int> mp1;
    for (int j = 1; j <= n; j++) {
      mp1[(a[j] + k) % m]++;
    }
    if (mp1.size() != msk.size())
      continue;
    else {
      for (auto it: mp1) {
        if (it.se != msk[it.fi]) {
          f = 1;
          break;
        }
      }
      if (!f) ans = min(ans, k);
    }
  }
  cout << ans << endl;

  return 0;
}
