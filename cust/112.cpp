/*************************************************************************
    > File Name: 112.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 07:19:15 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1;; i++) {
      if (n % 2 == 0)
        n /= 2;
      else {
        n = 3 * n + 1;
        n /= 2;
      }
      if (n == 1) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
