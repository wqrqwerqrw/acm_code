/*************************************************************************
    > File Name: h_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 17时34分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;
ll n, k;
int main() {
  cin >> n >> k;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i * i != n) v.push_back(n / i);
    }
  }
  sort(v.begin(), v.end());
  if (k <= v.size()) {
    cout << v[k - 1] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
