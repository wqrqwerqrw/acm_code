#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ft first
#define se second
#define pii pair<int, int>
#define db double
#define ls o << 1
#define rs o << 1 | 1
#define lowbit(x) (x & -x)
using namespace std;
const int M = 2e5 + 5;
ll n, m, k, a[M], b[M], c[M];

int chk(ll x) {
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = m, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (a[i] >= 0) {
        if (b[mid] * a[i] < x)
          l = mid + 1;
        else
          r = mid;
      } else {
        if (c[mid] * a[i] < x)
          l = mid + 1;
        else
          r = mid;
      }
    }
    if (a[i] >= 0) {
      if (b[l] * a[i] >= x)
        l--;
      res += m - l;
    } else {
      if (c[l] * a[i] >= x)
        l--;
      res += m - l;
    }
    //res += m - l + 1;
    //cout << i << " " << l << " " << res << endl;
    if (res >= k)
      return 1;
  }
  //cout << res << endl;
  return res >= k;
}

int main() {
  scanf("%lld %lld %lld", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }

  for (int i = 1; i <= m; i++) {
    scanf("%lld", &b[i]);
  }
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; i++) {
    c[i] = b[i];
  }
  reverse(c + 1, c + m + 1);
  ll l = -1e12, r = 1e12, mid;
  ll cnt = 0;
  while (l < r) {
    //assert(cnt <= 45);
    //cnt++;
    if (l + r < 0) {
      mid = (l + r) / 2;
      if ((l + r) % 2) {
        mid--;
      }
    } else
      mid = (l + r) / 2;
    if (chk(mid))
      l = mid + 1;
    else
      r = mid;
  }
  /*while (chk(l) && chk(l + 1))
        l++;
        */
  //chk(18);
  if (!chk(l))
    l--;
  cout << l << endl;
  return 0;
}
