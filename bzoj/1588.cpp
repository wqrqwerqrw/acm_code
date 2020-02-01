// Author : Wqr_
// Time : 19/09/20
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> stree;
stree bbt;
int n;
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  ll ans = 0;
  ll in;
  for (ll i = 1; i <= n; i++) {
    scanf("%lld", &in);
    if (i == 1) {
      ans += in;
      bbt.insert((in << 20) + i);
      continue;
    }
    ll a, b;
    stree::iterator itl = bbt.lower_bound(in << 20);
    stree::iterator itr = bbt.upper_bound(in << 20);
    --itl;
    a = (*itl) >> 20;
    b = (*itr) >> 20;
    if (itl == bbt.rend())
      ans += abs(in - b);
    else if (itr == bbt.end())
      ans += abs(in - a);
    else
      ans += min(abs(in - a), abs(in - b));
    bbt.insert((in << 20) + i);
  }
  printf("%lld\n", ans);
  return 0;
}