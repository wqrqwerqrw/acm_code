/*************************************************************************
    > File Name: 22.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 26 15:11:47 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int l = 2 * n + 1;
    for (int j = 1; j <= l; j++) {
      // j 为高
      if (j == 1 || j == 1 + n || j == 1 + n + n) {
        for (int i = 1; i <= l; i++) cout << "*";
      } else {
        for (int i = 1; i <= l; i++) {
          if (i == 1 || i == 1 + n || i == 1 + n + n)
            cout << "*";
          else
            cout << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}
