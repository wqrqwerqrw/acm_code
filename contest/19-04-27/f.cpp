/*************************************************************************
    > File Name: f.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 15时05分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int s[100100];
bool c(int d) {
  int num = 0;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] + s[n - 1 - i] >= d) {
      num++;
    } else {
      break;
    }
  }
  if (num >= n / 2)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", s + i);
  }
  //nlog(n)
  sort(s, s + n);
  int lb = 0, ub = 2000010;
  int mid;
  while (ub - lb > 1) {
    mid = (ub + lb) >> 1;
    if (c(mid))
      lb = mid;
    else
      ub = mid;
  }
  cout << lb << endl;
  return 0;
}
