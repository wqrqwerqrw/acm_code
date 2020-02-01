/*************************************************************************
    > File Name: 137.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Nov 11 22:08:25 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    int t = 0;
    unsigned int x;
    if (a != 0) t++, x = a;
    if (b != 0) t++, x = b;
    if (c != 0) t++, x = c;
    if (d != 0) t++, x = d;
    if (t != 1) {
      cout << "No" << endl;
      continue;
    }
    unsigned long int mi[20];
    mi[0] = 1;
    for (int i = 1; i < 16; i++) {
      mi[i] = mi[i - 1] * 4;
    }
    bool flag = false;
    for (int i = 0; i < 16; i++) {
      if (x == mi[i]) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
