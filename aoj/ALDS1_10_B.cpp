/*************************************************************************
    > File Name: ALDS1_10_B.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Oct 24 21:41:46 2018
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
  int p[n + 1];
  int m[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i - 1] >> p[i];
  }
  for (int i = 1; i <= n; i++) m[i][i] = 0;
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n; i++) {
      int j = i + l - 1;
      m[i][j] = (1 << 21);
      for (int k = i; k <= j - 1; k++) {
        m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
      }
    }
  }
  cout << m[1][n] << endl;
  return 0;
}
