/*************************************************************************
    > File Name: 21.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 28 07:17:54 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int n, x, y;
  while (cin >> n >> x >> y) {
    double want = (double)n * y / 100;
    int want2 = n * y / 100;
    if (want - want2 > 0) want += 1;
    if (x > want) {
      cout << 0 << endl;
      continue;
    } else {
      cout << (int)want - x << endl;
    }
  }
  return 0;
}
