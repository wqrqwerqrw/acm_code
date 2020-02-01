/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 13时39分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
double solve(int in) {
  double tore = 0;
  for (int i = 1; i <= in; i++) {
    tore += (double)1 / i;
  }
  return tore;
}
int main() {
  int n;
  while (cin >> n) {
    double out = solve(n);
    printf("%.12lf\n", out);
  }
  return 0;
}
