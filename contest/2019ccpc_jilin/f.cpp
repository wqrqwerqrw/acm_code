/*************************************************************************
    > File Name: f.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月23日 星期四 20时10分44秒
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
const int MAXN = 310;
int mapp[MAXN][MAXN];
int mapc[MAXN][MAXN];
int n;
int v = 0;
void solve() {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mapc[i][j] < mapc[i][k] + mapc[k][j]) {
          mapc[i][j] = mapc[i][k] + mapc[k][j];
        }
      }
    }
  }
  int ans = v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mapp[i][j] > mapc[i][j]) {
        ans--;
        mapp[i][j] = mapc[i][j];
        mapp[j][i] = mapc[i][j];
      }
    }
  }
  cout << ans << endl;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mapp[i][j];
      mapc[i][j] = mapp[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (mapp[i][j] > 0) v++;
    }
  }
  solve();
  return 0;
}
