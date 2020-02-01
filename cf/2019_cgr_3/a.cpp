/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 22时33分07秒
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
ll a, b, c;
int main() {
  iofuck;
  ll ans = 0;
  cin >> a >> b >> c;
  ans += c * 2;
  ll minn = min(a, b);
  ll maxn = max(a, b);
  if (maxn > minn) {
    ans += minn * 2 + 1;
  } else {
    ans += minn * 2;
  }
  cout << ans << endl;
  return 0;
}
