/*************************************************************************
    > File Name: 1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 19时00分48秒
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
int main() {
  iofuck;
  ll n;
  cin >> n;
  ll ans = n + n * (n - 1) / 2;
  n--;
  ans += n + n * (n - 1) / 2;
  cout << ans << endl;
  return 0;
}
