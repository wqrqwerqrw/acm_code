/*************************************************************************
    > File Name: 3278.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Mar 11 10:54:45 2019
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
bool book[200005];
struct w {
  int wz;
  int step;
} start;
int main() {
  int n, k;
  cin >> n >> k;
  start.wz = n;
  start.step = 0;
  queue<w> q;
  q.push(start);
  book[start.wz] = 1;
  bool flag = true;
  int now, next;
  if (n == k || k < n) flag = false;
  while (!q.empty() && flag) {
    now = q.front().wz;
    w tw;
    for (int i = 0; i < 3; i++) {
      switch (i) {
        case 0:
          next = now + 1;
          break;
        case 1:
          next = now - 1;
          break;
        case 2:
          next = now * 2;
          break;
      }
      if (next < 0 || next > 100001) continue;
      if (!book[next]) {
        tw.wz = next;
        tw.step = q.front().step + 1;
        book[next] = 1;
        q.push(tw);
        if (tw.wz == k) {
          flag = false;
          break;
        }
      }
    }
    q.pop();
  }
  if (n == k)
    cout << 0 << endl;
  else if (n > k)
    cout << n - k << endl;
  else
    cout << q.back().step;
  return 0;
}
