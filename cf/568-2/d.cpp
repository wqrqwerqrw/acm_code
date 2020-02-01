// Author : Wqr_
// Time : 2019年06月20日 星期四 00时13分38秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ll n;
ll a1[20000 + 5];
ll a2[20000 + 5];
int main() {
  iofuck;
  cin >> n;
  if (n == 2 && n == 3) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  for (ll i = 0; i < n; i++) {
    cin >> a1[i];
    a2[i] = a1[i];
  }
  sort(a1, a1 + n);
  map<ll, int> mapp;
  ll t3;
  for (int i = 0; i < n - 1; i++) {
    if (!i) {
      t3 = a1[1] - a1[0];
    }
    if (i) {
      mapp[__gcd(a1[i + 1] - a1[i], t3)]++;
      t3 = a1[i + 1] - a1[i];
    }
  }
  if (mapp.size() > 3) {
    cout << -1 << endl;
    return 0;
  }
  int maxnum = 0;
  ll tt;
  for (auto tmp: mapp) {
    cout << tmp.first << tmp.second << "-";
    if (tmp.second > maxnum) {
      tt = tmp.first;
      maxnum = tmp.second;
    }
  }
  ll minn;
  for (int i = 0; i < n - 1; i++) {
    if (a1[i + 1] - a1[i] == tt) {
      minn = a1[i];
    }
  }
  ll ji = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if ((a2[i] - minn) % tt != 0) {
      ji++;
      ans = i;
    }
  }
  if (ji > 1) {
    cout << -1 << endl;
  } else if (ans == 0) {
    cout << 1 << endl;
  } else {
    cout << ans + 1 << endl;
  }
  return 0;
}
