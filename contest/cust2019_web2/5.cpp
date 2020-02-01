/*************************************************************************
    > File Name: 5.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 15时03分43秒
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
int n, h;
int a[110];
int b[110];
int l[110];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int minn = 0x3f3f3f3f;
    int mini = 1000;
    int tmp;
    for (int i = 0; i < n; i++) {
      if (b[i] == -1) {
        tmp = a[i];
      } else {
        tmp = h + (h - a[i]);
      }
      if (tmp < minn) {
        minn = tmp;
        mini = i;
      }
    }
    cout << mini + 1 << endl;
  }
  return 0;
}
