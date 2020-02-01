/*************************************************************************
    > File Name: f.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 14时09分31秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int s[110];
int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    int a, b;
    memset(s, 0, sizeof(s));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);
      s[b]++;
      for (int j = b + 1; j < 110; j++) {
        ans += s[j];
      }
    }
    cout << ans % 1000000 << endl;
  }
  return 0;
}
