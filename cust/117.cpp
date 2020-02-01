/*************************************************************************
    > File Name: 117.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 07:44:33 2018
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    bool flag = true;
    int in;
    cin >> in;
    if (in % 4 == 0 || in % 7 == 0) flag = false;
    if (flag)
      cout << "happy" << endl;
    else
      cout << "sad" << endl;
  }
  return 0;
}
