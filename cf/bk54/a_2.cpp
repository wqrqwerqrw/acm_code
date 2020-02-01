/*************************************************************************
    > File Name: a_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Nov 13 00:23:38 2018
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
  string in;
  cin >> n >> in;
  char max = 'A';
  for (int i = 0; i < n; i++) {
    if (in[i] > max) max = in[i];
  }
  int a = 0;
  for (int i = n; i >= 0; i++) {
    if (in[i] == max) {
      a = i;
      break;
    }
  }
  in.erase(a, 1);
  cout << in;
  return 0;
}
