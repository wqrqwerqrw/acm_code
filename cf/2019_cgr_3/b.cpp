/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 22时44分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int nmax = 2 * 100000 + 5;
const int inf = 1 << 28;
ll n, m, ta, tb, k;
ll a[nmax], b[nmax];
int main() {
  iofuck;
  cin >> n >> m >> ta >> tb >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    //timeb[i] = b[i] + tb;
  }
  if (k >= n) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  for (ll i = 0; i <= k; i++) {
    ll tmp = lower_bound(b, b + m, a[i] + ta) - b;
    if (tmp == m || k - i >= (m - tmp)) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(b[tmp + k - i] + tb, ans);
  }
  cout << ans << endl;
  return 0;
}
