/*************************************************************************
    > File Name: e.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月11日 星期四 21时11分34秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int in;
  int n;
  cin >> n;
  int ans = 1;
  int now;
  bool book = 0;
  int all = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &in);
    all += in;
    if (in == 1) {
      if (book) {
        ans *= now;
        now = 1;
      } else {
        book = 1;
        now = 1;
      }
    } else {
      now++;
    }
  }
  if (all > 1) {
    cout << ans;
  } else
    cout << 0;
  return 0;
}
