/*************************************************************************
    > File Name: 23.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Sep 24 18:58:05 2018
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int book[n];
    for (int i = 0; i < n; i++) {
      cin >> book[i];
    }
    for (int num = 0;; num++) {
      bool flag = true;
      for (int i = 0; i < n; i++) {
        if (book[i] != i + 1) {
          flag = false;
          break;
        }
      }
      if (!flag) {
        int s = book[n - 1];
        for (int i = n - 1; i > 0; i--) {
          book[i] = book[i - 1];
        }
        book[0] = s;
      }
      if (flag) {
        cout << num << endl;
        break;
      }
    }
  }
  return 0;
}
