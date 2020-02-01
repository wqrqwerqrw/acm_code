/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 14时05分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int book[1000];
int main() {
  string in;
  int num;
  cin >> n >> k;
  int max = 1;
  int low = k;
  for (int i = 0; i <= k; i++) {
    book[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    cin >> num >> in;
    if (in[0] == 'S') {
      book[num] = 1;
    } else {
      book[num] = 0;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (book[i] == 0) {
      low = i;
      break;
    }
  }
  for (int i = low; i >= 1; i--) {
    if (book[i] == 1) {
      max = i;
      break;
    }
  }
  cout << max + 1 << " " << low - 1 << endl;
  return 0;
}
