/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月26日 星期日 23时06分30秒
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
using namespace std;
typedef long long ll;
int n, a, x, b, y;
int main() {
  cin >> n >> a >> x >> b >> y;
  int cura = a;
  int curb = b;
  bool flag = 0;
  for (;;) {
    if (cura == curb) {
      flag = 1;
    }
    if (cura == x || curb == y) break;
    cura++;
    if (cura > n) cura = 1;
    curb--;
    if (curb < 1) curb = n;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
