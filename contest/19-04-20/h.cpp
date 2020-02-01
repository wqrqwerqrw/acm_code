/*************************************************************************
    > File Name: h.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 16时12分40秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long n, k;
int main() {
  while (cin >> n >> k) {
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) ans++;
      if (ans == k) {
        cout << i << endl;
        break;
      }
    }
    ans++;
    if (ans < k) cout << -1 << endl;
    if (ans == k) cout << n << endl;
  }
  return 0;
}
