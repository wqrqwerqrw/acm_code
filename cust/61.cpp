/*************************************************************************
    > File Name: 61.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 28 09:42:18 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int x = 1;
    bool flag = true;
    bool flag2 = true;
    for (;;) {
      x *= n;
      for (int i = 1; x != 0; i++) {
        flag = true;
        int wei;
        wei = x % 10;
        x /= 10;
        if (i > 500) {
          break;
        }
        if (wei != 2 || wei != 3) {
          break;
        }
      }
      if (flag2) cout << "Unhappy" << endl;
    }
    if (!flag2) cout << x << endl;
  }
  return 0;
}
