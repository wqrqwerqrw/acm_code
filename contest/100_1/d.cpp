/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月10日 星期三 15时22分52秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int x;
int main() {
  cin >> x;
  int n = 0;
  for (;;) {
    if (x == 0) break;
    if (x >= 5) {
      x -= 5;
      n++;
    } else if (x >= 4) {
      x -= 4;
      n++;
    } else if (x >= 3) {
      x -= 3;
      n++;
    } else if (x >= 2) {
      x -= 2;
      n++;
    } else {
      x--;
      n++;
    }
  }
  cout << n;
  return 0;
}
