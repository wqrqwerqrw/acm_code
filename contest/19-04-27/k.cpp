/*************************************************************************
    > File Name: k.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 17时26分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct node {
  int x, y, r;
} ns[1100];
int tou[1100];
bool book[1100];
typedef pari<int, int> P;
bool touch(int i, int j) {
  int x = ns[i].x - ns[j].x;
  int y = ns[i].y - ns[j].y;
  int r = ns[i].r + ns[j].r;
  if (x * x + y * y == r * r)
    return 1;
  else
    return 0;
}
void dfs(int in, int num, P, int r) {
  book[in] = 1;
  if (tou[in] >= 2) {
    cout << "The input gear cannot move." << endl;
    return;
  }
  if (in == n - 1) {
    if (num % 2 == 0) {
    }
  }
  for (int i = 0; i < n; i++) {
    if (touch(in, i) && !book[i]) {
      book[i] = 1;
      dfs(i, num + 1);
      book[i] = 0;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ns[i].x >> ns[i].y >> ns[i].r;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (touch(i, j)) {
        tou[i]++;
        tou[j]++;
      }
    }
  }
  if (tou[n - 1] == 0) {
    cout << "The input gear is not conncted to the out put gear." << endl;
    return 0;
  }
  dfs(0, 1, P(1, 1), ns[0].r);
  return 0;
}
