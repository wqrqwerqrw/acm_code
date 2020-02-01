/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月17日 星期五 21时05分20秒
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
string begs, endss;

const int INF = 1 << 25;
int m;
long long d[150][150];
void solve() {
  long long ans = 0;
  for (int k = 0; k < 150; k++) {
    for (int i = 0; i < 150; i++) {
      for (int j = 0; j < 150; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 0; i < begs.length(); i++) {
    if (d[(int)begs[i]][(int)endss[i]] >= INF) {
      cout << -1 << endl;
      return;
    }
    ans += d[(int)begs[i]][(int)endss[i]];
  }
  cout << ans << endl;
}
int main() {
  cin >> begs >> endss;
  cin >> m;
  long long c;
  char a, b;
  for (int i = 0; i < 150; i++) {
    for (int j = 0; j < 150; j++) {
      if (i == j) {
        d[i][j] = 0;
        continue;
      }
      d[i][j] = INF;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    int ia = (int)a;
    int ib = (int)b;
    d[ia][ib] = min(c, d[ia][ib]);
  }
  solve();
  return 0;
}
