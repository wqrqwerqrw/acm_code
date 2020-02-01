/*************************************************************************
    > File Name: Re_ALDS1_3_A.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Feb 27 21:24:22 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
int main() {
  stack<int> S;
  int a, b, x;
  char in;
  while (cin >> in) {
    if (in == '-') {
      a = S.top(), S.pop();
      b = S.top(), S.pop();
      S.push(b - a);
    } else if (in == '+') {
      a = S.top(), S.pop();
      b = S.top(), S.pop();
      S.push(a + b);
    } else if (in == '*') {
      a = S.top(), S.pop();
      b = S.top(), S.pop();
      S.push(a * b);
    } else {
      S.push(atoi(&in));
      //cout << S.top() << endl;
    }
  }
  cout << S.top();
  return 0;
}
