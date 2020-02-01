#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 5e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
pll a[N];
set<ll> s1;
set<pll> S;

int32_t main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    S.clear();
    s1.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].fi >> a[i].se;
      S.insert({a[i].se, i});
    }
    sort(a + 1, a + 1 + n, greater<pll>());
    ll maxi = inf;
    ll ans = inf;
    for (int i = 1; i <= n; i++) {
      if (i == n) {
        ans = min(ans, abs(a[i].fi - *s1.rbegin()));
        break;
      }
      int p;
      if (s1.empty())
        p = 0;
      else {
        p = *s1.rbegin();
        ans = min(ans, abs(p - a[i].fi));
      }
      S.erase({a[i].se, i});
      auto it = S.lower_bound(make_pair(a[i].fi, 0));
      if (it != S.end()) {
        ll a1 = (*it).fi;
        if (a1 >= p) ans = min(ans, abs(a1 - a[i].fi));
      }
      if (it != S.begin()) {
        ll a2 = (*--it).fi;
        if (a2 >= p) ans = min(ans, abs(a[i].fi - a2));
      }
      s1.insert(a[i].se);
      S.insert({a[i].se, i});
    }
    cout << ans << endl;
  }
  return 0;
}