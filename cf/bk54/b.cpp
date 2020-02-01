/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Nov 12 22:39:57 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool zs[500000000];
int main() {
  int n;
  int num = 0;
  cin >> n;
  for (int i = 0; i < 500000000; i++) {
    zs[i] = true;
  }
  zs[0] = false;
  zs[1] = false;
  for (int i = 0; i < 10000; i++) {
    if (zs[i]) {
      for (int j = 2; i * j < 10000; j++) {
        zs[i * j] = 0;
      }
    }
  }
  for (int i = 0; i < 500000000; i++)
    cout << zs[i];
  while (n) {
    int min = 0;
    for (int i = 2; i <= n; i++) {
      if (n % i == 0 && zs[i]) {
        min = i;
        break;
      }
    }
    n -= min;
    num++;
  }
  cout << num;
  return 0;
}
