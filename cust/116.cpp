/*************************************************************************
    > File Name: 116.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 07:35:04 2018
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int out = 0;
    int in;
    for (int i = 1; i <= n; i++) {
      cin >> in;
      if (i % 2 != 0) {
        out += in;
      } else {
        out -= in;
      }
    }
    cout << out << endl;
  }
  return 0;
}
