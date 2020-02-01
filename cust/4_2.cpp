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
long int gcd(long int a, long int b) {
  return a % b == 0 ? b : gcd(b, a % b);
}
long int zx(long int a, long int b) {
  return a * b / gcd(a, b);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int a, b;
    cin >> a >> b;
    if (a == 2 && b == 1) {
      cout << "Yes" << endl;
      continue;
    }
    long int zx1 = zx(a, b);
    if (zx1 != a * b) {
      cout << "No ";
      cout << zx1 / b << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
