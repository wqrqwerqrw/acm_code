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

pii a[10];
set<pii> s, s1, s2;

int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  IOS;
  int _;
  cin >> _;
  while (_--) {
    s.clear();
    s1.clear();
    s2.clear();
    for (int i = 1; i <= 4; i++) cin >> a[i].fi >> a[i].se, s.insert(a[i]);
    a[5] = {a[1].fi, a[2].se};
    a[6] = {a[2].fi, a[1].se};
    a[7] = {a[3].fi, a[4].se};
    a[8] = {a[4].fi, a[3].se};
    int lef = min(a[3].fi, a[4].fi);
    int rig = max(a[3].fi, a[4].fi);
    int d = min(a[3].se, a[4].se);
    int up = max(a[3].se, a[4].se);
    int lef2 = min(a[1].fi, a[2].fi);
    int rig2 = max(a[1].fi, a[2].fi);
    int d2 = min(a[1].se, a[2].se);
    int up2 = max(a[1].se, a[2].se);
    s.insert({a[1].fi, a[2].se});
    s.insert({a[2].fi, a[1].se});
    s.insert({a[3].fi, a[4].se});
    s.insert({a[4].fi, a[3].se});
    s1.insert(a[1]);
    s1.insert(a[2]);
    s1.insert(a[5]);
    s1.insert(a[6]);
    s2.insert(a[3]);
    s2.insert(a[4]);
    s2.insert(a[7]);
    s2.insert(a[8]);
    if (s.size() == 4) {
      cout << 2 << endl;
      continue;
    }
    int in = 0, on = 0;
    if (!(lef >= lef2 && lef <= rig2 && rig >= lef2 && rig <= rig2)) {
      for (auto it: s1) {
        if (it.fi > lef && it.fi < rig && it.se > d && it.se < up)
          in++;
        else if ((it.fi == lef || it.fi == rig) && it.se >= d && it.se <= up)
          on++;
        else if ((it.se == d || it.se == up) && it.fi >= lef && it.fi <= rig)
          on++;
      }
    } else {
      int t1 = lef, t2 = rig, t3 = up, t4 = d;
      lef = lef2, rig = rig2;
      up = up2, d = d2;
      lef2 = t1, rig2 = t2, up2 = t3, d2 = t4;
      for (auto it: s2) {
        if (it.fi > lef && it.fi < rig && it.se > d && it.se < up)
          in++;
        else if ((it.fi == lef || it.fi == rig) && it.se >= d && it.se <= up)
          on++;
        else if ((it.se == d || it.se == up) && it.fi >= lef && it.fi <= rig)
          on++;
      }
    }
    int c = 0;
    if (up == up2) c++;
    if (d == d2) c++;
    if (lef == lef2) c++;
    if (rig == rig2) c++;
    if (on == 3) {
      cout << 3 << endl;
      continue;
    }
    if (on == 4 && c == 3) {
      cout << 3 << endl;
      continue;
    }
    if (on == 4 && c == 2) {
      cout << 4 << endl;
      continue;
    }
    if (in == 0 && on == 0 && lef < rig2 && lef2 < rig) {
      cout << 6 << endl;
      continue;
    }
    if (on == 2 && in == 0 && (lef == rig2 || lef2 == rig || up == d || up2 == d2)) {
      cout << 3 << endl;
      continue;
    }

    if (on == 2 && in == 0 && c == 2) {
      cout << 4 << endl;
      continue;
    }
    if (on == 2 && in == 0) {
      cout << 5 << endl;
      continue;
    }
    if (in == 2 && on == 2) {
      cout << 3 << endl;
      continue;
    }
    if (in && in != 4) {
      cout << 4 << endl;
      continue;
    }
    cout << 3 << endl;
  }
  return 0;
}