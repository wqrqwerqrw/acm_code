// Author : Wqr_
// Time : 19/10/07
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
const ll amax = 1e5 + 50;
ll a, b, n, l[amax], tot[amax];
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll t;
  cin >> t;
  for (ll kase = 1; kase <= t; kase++) {
    cin >> a >> b >> n;
    for (ll i = 1; i <= a; i++) {
      cin >> l[i];
    }
    tot[1] = 1;
    for (ll i = 2; i <= a; i++) {
      tot[i] = tot[i - 1] + l[i - 1];
    }
    ll cur = a;
    while (--n) {
      cur = upper_bound(tot + 1, tot + 1 + a, cur) - (tot + 1);
      if (cur == 1) break;
      if (tot[cur] == cur) break;
    }
    ll ans = upper_bound(tot + 1, tot + 1 + a, cur) - (tot + 1);
    cout << "Case #" << kase << ": " << ans << "-" << cur - tot[ans] + 1 << endl;
  }
  return 0;
}