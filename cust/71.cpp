/*************************************************************************
    > File Name: 71.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep 23 09:24:31 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int k;
  while (cin >> k) {
    long long int num = 2;
    if (k == 0) {
      cout << 1 << endl;
      continue;
    }
    for (int i = 1; i < k; i++) {
      num *= 2;
    }
    cout << num << endl;
  }
}
