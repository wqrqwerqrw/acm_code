/*************************************************************************
    > File Name: 3253.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Mar  8 16:07:53 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int in[1001];
int main() {
  int r, n;
  while (cin >> r >> n) {
    int ans = 0;
    if (r == -1 && n == -1) break;
    for (int i = 0; i < n; i++) {
      cin >> in[i];
    }
    sort(in, in + n);
    int i = 0;
    while (i < n) {
      int s = in[i++];
      while (i < n && in[i] <= s + r) i++;
      int p = in[i - 1];
      while (i < n && in[i] <= p + r) i++;

      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}