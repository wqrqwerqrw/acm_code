/*************************************************************************
    > File Name: 2386.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Mar  7 21:28:27 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
char map[110][110];
void dfs(int y, int x) {
  map[y][x] = '.';
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      int ty = y + i;
      int tx = x + j;
      if (tx >= 0 && ty >= 0 && tx <= m && ty <= n && map[ty][tx] == 'W')
        dfs(ty, tx);
    }
  }
  return;
}
int main() {
  cin >> n >> m;
  int num = 0;
  // i zong, j heng
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == '.')
        continue;
      else if (map[i][j] == 'W') {
        dfs(i, j);
        num++;
      }
    }
  }
  cout << num;
  return 0;
}
