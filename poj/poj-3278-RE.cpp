/*************************************************************************
    > File Name: 3278.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Mar 11 10:25:20 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int minn = 9999999;
int book[200005];
int n, k;
void dfs(int cnt, int sum) {
  if (sum > minn) return;
  if (cnt == k) {
    if (minn > sum) minn = sum;
    return;
  }
  if (cnt < 0 || cnt > 100000)
    return;
  else if (cnt > k) {
    if (!book[cnt - 1]) {
      book[cnt - 1] = 1;
      dfs(cnt - 1, sum + 1);
      book[cnt - 1] = 0;
    }
  } else if (cnt < k) {
    if (!book[cnt - 1]) {
      book[cnt - 1] = 1;
      dfs(cnt - 1, sum + 1);
      book[cnt - 1] = 0;
    }
    if (!book[cnt + 1]) {
      book[cnt + 1] = 1;
      dfs(cnt + 1, sum + 1);
      book[cnt + 1] = 0;
    }
    if (!book[cnt * 2]) {
      book[cnt * 2] = 1;
      dfs(cnt * 2, sum + 1);
      book[cnt * 2] = 0;
    }
  }
  return;
}
int main() {
  cin >> n >> k;
  book[n] = 1;
  dfs(n, 0);
  cout << minn;
  return 0;
}
