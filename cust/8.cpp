/*************************************************************************
    > File Name: 8.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 17:50:21 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool ifis(char in) {
  if (in == 'a') {
    return true;
  }
  if (in == 'e') {
    return true;
  }
  if (in == 'i') {
    return true;
  }
  if (in == 'o') {
    return true;
  }
  if (in == 'u') {
    return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    bool flag = true;
    for (int j = 0; j < s.size(); j++) {
      if (ifis(s[j])) {
        break;
      } else if (j == s.size() - 1) {
        flag = false;
      }
    }
    if (flag) {
      cout << "XP is a genius." << endl;
    } else {
      cout << "WTF." << endl;
    }
  }
  return 0;
}
