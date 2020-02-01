/*************************************************************************
    > File Name: 4_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Nov  2 12:14:27 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long gcd(int a, int b) {
  return a % b == 0 ? b : gcd(b, a % b);
}
int main() {
  int a, b, c, d, e;
  int a1, a2;
  cin >> c >> d;
  b = gcd(c, d);
  int cis[100] = {0};
  int dis[100] = {0};
  int gcd[100] = {0};
  int j = 0;
  for (int i = 1; i <= b; i++) {
    if (c % i == 0) cis[j++] = i;
  }
  for (int i = 1, j = 0; i <= b; i++) {
    if (d % i == 0) dis[j++] = i;
  }
  int x = 0;
  for (int i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      if (cis[i] == dis[j] && cis[i] >= 10) {
        gcd[x++] = cis[i];
        cis[i] = 0;
        dis[i] = 0;
      }
    }
  }
  for (int i = 0; i < 100; i++) {
    if (gcd[i] != 0) cout << gcd[i] << endl;
  }
  a1 = c / b;
  a2 = d / b;
  a = a1 / 10 * 10 + a2 % 10;
  e = a * b;
  cout << e;
  return 0;
}
