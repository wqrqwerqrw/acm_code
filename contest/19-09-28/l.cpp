// Author : Wqr_
// Time : 19/09/28
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttl(x) cout << "#" << (x) << "#" << endl;
#define ttt(x) cout << "#" << (x) << "#";
#define ttn cout << "####" << endl;
using namespace std;
typedef long long ll;
ll a[26];
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string in;
  cin >> in;
  for (auto c: in) {
    a[c - 'a']++;
  }
  ll ans = 2;
  ll min = 1e17;
  for (int i = 2; i <= 1000000; i++) {
    ll cnt = 0;
    for (int j = 0; j < 26; j++) {
      cnt += a[j] * a[j] * (a[j] % i);
    }
    if (cnt < min) {
      min = cnt;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}