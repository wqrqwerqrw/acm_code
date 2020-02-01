/*************************************************************************
    > File Name: b_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月27日 星期一 00时09分21秒
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
typedef pair<int, int> P;
P ps[300030];
int n, m;
bool check(int a, int b) {
  bool tore = 1;
  for (int i = 0; i < m; i++) {
    if (ps[i].first != a && ps[i].first != b && ps[i].second != a && ps[i].second != b) {
      tore = 0;
      break;
    }
  }
  return tore;
}
int main() {
  cin >> n >> m;
  int a, b;
  int ta, tb, tc = -1, td = -1;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    ps[i].first = a;
    ps[i].second = b;
    if (i == 0) {
      ta = a;
      tb = b;
    }
    if (a != ta && a != tb && b != ta && b != tb) {
      tc = a;
      td = b;
    }
  }
  bool ans = 0;
  //printf("%d-%d-%d-%d\n", ta, tb, tc, td);
  if (check(ta, tc)) ans = 1;
  if (check(ta, td)) ans = 1;
  if (check(tb, tc)) ans = 1;
  if (check(tb, td)) ans = 1;
  if (check(ta, tb)) ans = 1;
  if (check(tc, td)) ans = 1;
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
