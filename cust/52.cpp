/*************************************************************************
    > File Name: 52.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep 23 18:15:37 2018
 ************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int x, y;
    cin >> s;
    cin >> x >> y;
    int k = 0, b = 0;
    bool iffu = false;
    int xwz, bwz;
    int kws, bws;
    if (s[2] == '-') iffu = true;
    for (int i = 0; i <= s.size(); i++) {
      if (s[i] == 'x') {
        xwz = i;
        break;
      }
    }
    if (iffu == true) {
      kws = xwz - 2 - 1;
    }
    if (iffu == false) {
      kws = xwz - 1 - 1;
    }
    if (kws == 0) {
      k = 1;
      if (iffu == true) k *= -1;
    } else {
      if (iffu == true) {
        for (int i = 3; i < xwz; i++) {
          k += ((s[i] - '0') * pow(10, kws - 1));
          kws--;
        }
        k *= -1;
      }
      if (iffu == false) {
        for (int i = 2; i < xwz; i++) {
          k += ((s[i] - '0') * pow(10, kws - 1));
          kws--;
        }
      }
    }
    bwz = xwz + 2;
    if (s[bwz] == '0')
      b = 0;
    else {
      b = 0;
      bws = s.size() - bwz;
      for (int i = bwz; i < s.size(); i++) {
        b += ((s[i] - '0') * pow(10, bws - 1));
        bws--;
      }
      if (s[xwz + 1] == '-') b = (-1) * b;
    }
    if (b == y - k * x)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
