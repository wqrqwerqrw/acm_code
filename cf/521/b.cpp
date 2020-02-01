/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Nov 16 23:09:38 2018
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
  cin >> n;
  int flag[n];
  int out = 0;
  for (int i = 0; i < n; i++) {
    cin >> flag[i];
  }
  for (int i = 1; i < n - 1; i++) {
    if (flag[i] == 0 && (flag[i - 1] == 1 && flag[i + 1] == 1)) {
      out++;
      flag[i + 1] = 0;
    }
  }
  cout << out;
  return 0;
}
