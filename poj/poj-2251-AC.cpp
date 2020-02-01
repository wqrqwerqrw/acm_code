/*************************************************************************
    > File Name: 2241.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Mar 10 20:43:53 2019
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
struct w {
  short a, b, c;
  short step;
} start;
char map[31][31][31];
bool book[31][31][31];
int main() {
  short next[6][3] = {
      {1, 0, 0},
      {-1, 0, 0},
      {0, 1, 0},
      {0, -1, 0},
      {0, 0, -1},
      {0, 0, 1}};
  short l, r, c;
  while (cin >> l >> r >> c) {
    if (l == 0 && r == 0 && c == 0) break;
    memset(book, 0, sizeof(book));
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          cin >> map[i][j][k];
          if (map[i][j][k] == 'S') {
            start.a = i;
            start.b = j;
            start.c = k;
          }
        }
      }
    }
    // 高, 长, 宽
    queue<w> q;
    start.step = 0;
    q.push(start);
    bool flag = true;
    while (flag) {
      short ta, tb, tc;
      w tq = q.front();
      w toin;
      for (int i = 0; i < 6; i++) {
        ta = tq.a + next[i][2];
        tb = tq.b + next[i][1];
        tc = tq.c + next[i][0];
        if (ta >= l || tb >= r || tc >= c || ta < 0 || tb < 0 || tc < 0 || map[ta][tb][tc] == '#')
          continue;
        toin.a = ta;
        toin.b = tb;
        toin.c = tc;
        toin.step = tq.step + 1;
        if (map[ta][tb][tc] == 'E') {
          q.push(toin);
          flag = false;
          break;
        }
        if (!book[ta][tb][tc]) {
          q.push(toin);
          book[ta][tb][tc] = 1;
        }
      }
      q.pop();
      if (q.empty()) break;
    }
    if (q.empty())
      cout << "Trapped!" << endl;
    else
      cout << "Escaped in " << q.back().step << " minute(s)." << endl;
  }
  return 0;
}
