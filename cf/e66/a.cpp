/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月05日 星期三 22时22分36秒
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
ll n, k;
int main() {
  iofuck;
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ll ans = 0;
    for (; n > 0;) {
      if (n % k == 0) {
        n /= k;
        ans++;
      } else {
        ans += n % k;
        n -= (n % k);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
