/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 16时17分54秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[550][550];
int d[550][550];
bool book[550][550];
int m, n;
typedef pair<int, int> P;
void solve(int x, int y) {
  queue<P> q;
  book[x][y] = 1;
  //d[x][y] = 1;
  q.push(P(x, y));
  while (!q.empty()) {
    P p = q.front();
    q.pop();
    if (p.first == m - 1 && p.second == n - 1) break;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (abs(i) == abs(j)) continue;
        int tx = p.first + i * map[p.first][p.second];
        int ty = p.second + j * map[p.first][p.second];
        if (tx >= m || tx < 0 || ty >= n || ty < 0 || book[tx][ty]) continue;
        q.push(P(tx, ty));
        book[tx][ty] = 1;
        d[tx][ty] = d[p.first][p.second] + 1;
      }
    }
  }
  if (d[m - 1][n - 1] == 0)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << d[m - 1][n - 1] << endl;
}
int main() {
  cin >> m >> n;
  char in;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> in;
      map[i][j] = (int)in - '0';
    }
  }
  solve(0, 0);
  return 0;
}
