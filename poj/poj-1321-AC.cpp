/*************************************************************************
    > File Name: 1321.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Mar 10 18:27:37 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k;
char map[10][10];
int ans = 0;
int sum = 0;
int book[10];
void dfs(int hang) {
  if (sum == k) {
    ans++;
    return;
  }
  if (hang >= n) return;
  for (int j = 0; j < n; j++) {
    if (map[hang][j] == '#' && book[j] == 0) {
      sum++;
      book[j] = 1;
      dfs(hang + 1);
      sum--;
      book[j] = 0;
    }
  }
  dfs(hang + 1);
}
int main() {
  while (cin >> n >> k) {
    if (n == -1 && k == -1) break;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> map[i][j];
      }
    }
    memset(book, 0, sizeof(book));
    ans = 0;
    sum = 0;
    dfs(0);
    cout << ans << endl;
  }
  return 0;
}
