/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月25日 星期四 19时19分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int a[1100];
int main() {
  int n;
  cin >> n;
  int in;
  for (int i = 0; i < n; i++) {
    scanf("%d", &in);
    if (i) cout << " ";
    if (in % 2 == 0)
      cout << in - 1;
    else
      cout << in;
  }
  return 0;
}
