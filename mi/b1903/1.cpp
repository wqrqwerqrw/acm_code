/*************************************************************************
    > File Name: 1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月29日 星期五 18时56分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int m[1000000], n[1000000];
int main() {
  int a, b, c, d, e;
  while (cin >> a >> b >> c >> d >> e) {
    memset(m, 0, sizeof(m));
    memset(n, 0, sizeof(n));
    int x1, x2, x3, x4, x5;
    for (int i = -50; i <= 50; i++) {
      if (!i) continue;
      for (int j = -50; j <= 50; j++) {
        if (!j) continue;
        long tmp = d * i * i * i + e * j * j * j;
        if (tmp > 0)
          m[tmp]++;
        else
          n[-tmp]++;
      }
    }
    int ans = 0;
    for (int i = -50; i <= 50; i++) {
      if (!i) continue;
      for (int j = -50; j <= 50; j++) {
        if (!j) continue;
        for (int k = -50; k <= 50; k++) {
          if (!k) continue;
          long tmp = a * pow(i, 3) + b * pow(j, 3) + b * pow(k, 3);
          if (tmp > 0 && m[tmp]) {
            m[tmp]--;
            ans++;
          } else if (tmp < 0 && n[-tmp]) {
            n[-tmp]--;
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
