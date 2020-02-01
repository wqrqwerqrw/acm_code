/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月17日 星期五 23时20分52秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
int k;
char cs[5] = {'a', 'e', 'i', 'o', 'u'};
int main() {
  cin >> k;
  if (k < 25) {
    cout << -1 << endl;
    return 0;
  }
  bool flag = 0;
  int book = 0;
  for (int i = 5; i <= sqrt(k); i++) {
    if (k % i == 0) {
      flag = 1;
      book = i;
      break;
    }
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  int x = book;
  int y = k / book;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cout << cs[(i + j) % 5];
    }
  }
  return 0;
}
