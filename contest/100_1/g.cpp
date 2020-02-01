/*************************************************************************
    > File Name: g.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月10日 星期三 18时16分40秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int sum = 0;
  while (a > 0 && b > 0) {
    if (a >= 2 || b >= 2) {
      sum++;
      if (a >= b) {
        b++;
        a -= 2;
      } else {
        b -= 2;
        a++;
      }
    } else
      break;
  }
  cout << sum;
  return 0;
}
