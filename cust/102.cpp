/*************************************************************************
    > File Name: 102.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 12:19:52 2018
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double PI = 3.14;
    double r = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    printf("%.2lf\n", PI * r * r);
  }
  return 0;
}
