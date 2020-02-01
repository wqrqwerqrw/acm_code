/*************************************************************************
    > File Name: 81.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Nov  7 19:25:29 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
  string in;
  while (cin >> in) {
    bool flag = true;
    for (int i = 0; i < in.size(); i++) {
      if (in[i] == 'F') {
        cout << in << endl;
        flag = false;
        break;
      }
      if (in[i] == 'Z') {
        cout << in << endl;
        flag = false;
        break;
      }
      if (in[i] == 'K') {
        cout << in << endl;
        flag = false;
        break;
      }
      if (in[i] == 'L') {
        cout << in << endl;
        flag = false;
        break;
      }
    }
    if (flag) cout << "FZKLWqr_" << endl;
  }
  return 0;
}
