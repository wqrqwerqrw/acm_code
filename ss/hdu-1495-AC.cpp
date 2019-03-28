/*************************************************************************
    > File Name: 1495.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Mar 13 21:50:36 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int s, n, m;
bool book[102][102][102];
struct node{
    int deep;
    int sc;
    int nc;
    int mc;
};
node opera(int ope, node in) {
  if (ope == 1) {
    // s->n
    for (;;) {
      if (in.sc == 0 || in.nc == n) break;
      in.sc--;
      in.nc++;
    }
  } else if (ope == 2) {
    // s->m
    for (;;) {
      if (in.sc == 0 || in.mc == m) break;
      in.sc--;
      in.mc++;
    }
  } else if (ope == 3) {
    // n->m
    for (;;) {
      if (in.nc == 0 || in.mc == m) break;
      in.nc--;
      in.mc++;
    }
  } else if (ope == 4) {
    // n->s
    for (;;) {
      if (in.nc == 0 || in.sc == s) break;
      in.nc--;
      in.sc++;
    }
  } else if (ope == 5) {
    // m->s
    for (;;) {
      if (in.mc == 0 || in.sc == s) break;
      in.mc--;
      in.sc++;
    }
  } else if (ope == 6) {
    // m->n
    for (;;) {
      if (in.mc == 0 || in.nc == n) break;
      in.mc--;
      in.nc++;
    }
  }
  in.deep = in.deep + 1;
  return in;
}
void bfs() {
  memset(book, 0, sizeof(book));
  queue<node> q;
  node first;
  first.deep = 0;
  first.sc = s;
  first.nc = 0;
  first.mc = 0;
  book[first.sc][first.nc][first.mc] = 1;
  q.push(first);
  bool flag = true;
  while (!q.empty() && flag) {
    node get = q.front();
    q.pop();
    node tmp;
    for (int i = 1; i <= 6; i++) {
      tmp = opera(i, get);
      if (book[tmp.sc][tmp.nc][tmp.mc]) continue;
      book[tmp.sc][tmp.nc][tmp.mc] = 1;
      q.push(tmp);
      if ((tmp.sc == s / 2 && tmp.nc == s / 2) ||
          (tmp.sc == s / 2 && tmp.mc == s / 2) ||
          (tmp.nc == s / 2 && tmp.mc == s / 2)) {
        flag = false;
        break;
      }
    }
  }
  if (flag) {
    cout << "NO" << endl;
  } else {
    cout << q.back().deep << endl;
  }
}
int main() {
  while (cin >> s >> n >> m) {
    if (s == 0 && n == 0 && m == 0) break;
    if (s % 2 != 0)
      cout << "NO" << endl;
    else
      bfs();
  }
  return 0;
}
