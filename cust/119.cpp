/*************************************************************************
    > File Name: 119.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 10:23:32 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int in;
  while (cin >> in) {
    int out[1000];
    int i = 0;
    int a;
    bool flag = false;
    if (in == 1 || in == 0) flag = true;
    for (i;; i++) {
      out[i] = in % 2;
      in /= 2;
      if (in == 1 || in == 0) {
        a = in;
        break;
      }
    }
    if (!flag) cout << a;
    for (int j = i; j >= 0; j--) {
      cout << out[j];
    }
    cout << endl;
  }
  return 0;
}
