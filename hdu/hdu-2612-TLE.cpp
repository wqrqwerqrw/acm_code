/*************************************************************************
    > File Name: 2612.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Mar 14 17:46:23 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
char map[202][202];
struct point {
  int x, y, deep;
} kfc[100], begY, begM;
bool book[202][202];
int kfcnum;
int n, m;
int bfs(point beg, point kfc) {
  memset(book, 0, sizeof(book));
  int move[4][2] = {
      {1, 0},
      {-1, 0},
      {0, -1},
      {0, 1}};
  queue<point> q;
  q.push(beg);
  bool flag = true;
  while (flag && !q.empty()) {
    point get = q.front();
    q.pop();
    point tmp;
    for (int i = 0; i < 4; i++) {
      tmp.x = get.x + move[i][0];
      tmp.y = get.y + move[i][1];
      if (book[tmp.x][tmp.y]) continue;
      if (tmp.x >= n || tmp.x < 0) continue;
      if (tmp.y >= m || tmp.y < 0) continue;
      if (map[tmp.x][tmp.y] == '#') continue;
      book[tmp.x][tmp.y] = 1;
      tmp.deep = get.deep + 1;
      q.push(tmp);
      if (tmp.x == kfc.x && tmp.y == kfc.y) {
        flag = false;
        break;
      }
    }
  }
  if (flag)
    return 99999999;
  else
    return q.back().deep;
}
void move() {
  int mins = 99999999;
  for (int i = 0; i < kfcnum; i++) {
    int stepY = bfs(begY, kfc[i]);
    int stepM = bfs(begM, kfc[i]);
    mins = min(mins, stepY + stepM);
  }
  cout << mins * 11 << endl;
}
int main() {
  while (cin >> n >> m) {
    kfcnum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> map[i][j];
        if (map[i][j] == '@') {
          kfc[kfcnum].x = i;
          kfc[kfcnum].y = j;
          kfc[kfcnum].deep = -1;
          kfcnum++;
        } else if (map[i][j] == 'Y') {
          begY.x = i;
          begY.y = j;
          begY.deep = 0;
        } else if (map[i][j] == 'M') {
          begM.x = i;
          begM.y = j;
          begM.deep = 0;
        }
      }
    }
    move();
  }
  return 0;
}
