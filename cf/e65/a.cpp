/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月15日 星期三 22时28分36秒
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
#define MAXN 200100
using namespace std;
typedef long long ll;
bool book[15];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string in;
    cin >> in;
    memset(book, 0, sizeof(book));
    int min8 = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
      book[in[i] - '0'] = 1;
      if (in[i] == '8') {
        min8 = min(min8, i);
      }
    }
    if (!book[8]) {
      cout << "NO" << endl;
      continue;
    }
    if (n - min8 >= 11) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
