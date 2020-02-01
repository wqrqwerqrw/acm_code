/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月14日 星期二 22时16分46秒
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
#define MAX_N 200100
using namespace std;
typedef long long ll;
int n, x, y;
int a[MAX_N];
int b[MAX_N];
int main() {
  cin >> n >> x >> y;
  string in;
  cin >> in;
  for (int i = 0; i < n; i++) {
    a[i] = in[i] - '0';
  }
  int ans = 0;
  for (int i = 0; i < x + 1; i++) {
    b[i] = a[n - 1 - i];
  }
  for (int i = 0; i < x + 1; i++) {
    if (i == x || i == y) continue;
    if (b[i]) ans++;
  }
  //if(!b[x]) ans++;
  if (!b[y]) ans++;
  cout << ans << endl;
  return 0;
}
