/*************************************************************************
    > File Name: 3617.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Mar  8 09:58:59 2019
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
  int n;
  while (cin >> n) {
    string in;
    string out;
    for (int i = 0; i < n; i++) {
      string inw;
      cin >> inw;
      in += inw;
    }
    int left = 0;
    int right = in.length() - 1;
    int cnt = 0;
    while (left <= right) {
      bool flag = false;
      //true left
      //false right
      for (int i = 0; i <= right - left; i++) {
        if (in[left + i] < in[right - i]) {
          flag = true;
          break;
        }
        if (in[left + i] > in[right - i]) {
          flag = false;
          break;
        }
      }
      cnt++;
      if (flag) cout << in[left++];
      if (!flag) cout << in[right--];
      if (cnt % 80 == 0) cout << endl;
    }
    cout << endl;
  }
  return 0;
}
