/*************************************************************************
    > File Name: 3414.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Mar 12 20:06:43 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
// ope储存达到次节点的上一步操作
struct node {
  short ca;
  short cb;
  short ope;
  short deep;
  short father;
  short self;
} first;
short maxa, maxb, c;
bool book[101][101];
node opera(short ope, node in) {
  if (ope == 1) {
    in.ca = maxa;
  } else if (ope == 2) {
    in.cb = maxb;
  } else if (ope == 3) {
    in.ca = 0;
  } else if (ope == 4) {
    in.cb = 0;
  } else if (ope == 5) {
    for (;;) {
      if (in.ca == 0 || in.cb == maxb) break;
      in.ca--;
      in.cb++;
    }
  } else if (ope = 6) {
    for (;;) {
      if (in.ca == maxa || in.cb == 0) break;
      in.ca++;
      in.cb--;
    }
  }
  return in;
}
// map 储存操作
// node 储存节点, 操作数
void bfs() {
  int mark = 0;
  map<short, node> map;
  first.ca = 0;
  first.cb = 0;
  first.ope = -1;
  first.deep = 0;
  first.father = -1;
  first.self = mark;
  map[mark] = first;
  queue<node> q;
  q.push(first);
  bool flag = true;
  while (!q.empty() && flag) {
    node get = q.front();
    node tmp;
    for (short i = 1; i <= 6; i++) {
      tmp = opera(i, get);
      if (book[tmp.ca][tmp.cb]) continue;
      mark++;
      tmp.self = mark;
      tmp.father = get.self;
      tmp.deep = get.deep + 1;
      tmp.ope = i;
      map[mark] = tmp;
      q.push(tmp);
      book[tmp.ca][tmp.cb] = 1;
      if (tmp.ca == c || tmp.cb == c) {
        flag = false;
        break;
      }
    }
    q.pop();
  }
  short step[10000];
  int ji = 0;
  if (flag) {
    cout << "impossible" << endl;
  } else {
    node out = q.back();
    cout << out.deep << endl;
    for (;;) {
      if (out.ope == -1) break;
      step[++ji] = out.ope;
      out = map[out.father];
    }
    for (int i = ji; i > 0; i--) {
      if (step[i] == 1) {
        cout << "FILL(1)" << endl;
      } else if (step[i] == 2) {
        cout << "FILL(2)" << endl;
      } else if (step[i] == 3) {
        cout << "DROP(1)" << endl;
      } else if (step[i] == 4) {
        cout << "DROP(2)" << endl;
      } else if (step[i] == 5) {
        cout << "POUR(1,2)" << endl;
      } else if (step[i] == 6) {
        cout << "POUR(2,1)" << endl;
      }
    }
  }
}
int main() {
  cin >> maxa >> maxb >> c;
  if (c > maxa && c > maxb) {
    cout << "impossible" << endl;
  } else
    bfs();
  return 0;
}