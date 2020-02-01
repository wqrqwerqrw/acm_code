/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 22时09分33秒
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
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int nmax = 1e5 + 5;
int n;
int a[nmax];
int b[nmax];
bool book[nmax];
int main() {
  iofuck;
  cin >> n;
  bool flag1 = 0;
  bool flag2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2)
      flag2 = 1;
    else
      flag1 = 1;
  }
  if (flag1 && flag2)
    sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
