/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月16日 星期四 00时04分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
string in;
bool ans[200200];
bool br = 0;
int minl = 0;
void syn() {
  for (int i = minl; i < n; i++) {
    if (in[i] == '(') {
      minl = i;
      return;
    }
  }
}
void dfs(int l, int r) {
  if (r >= n || l >= n) return;
  if (in[l] == '(' && in[r] == ')') {
    if (l == minl) br = !br;
    ans[l] = br;
    ans[r] = br;
    in[l] = '*';
    in[r] = '*';
    /*
        for(int i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
        cout << in << endl;
        */
    if (in[r + 1] == '(')
      dfs(r + 1, r + 2);
    if (l >= minl) {
      syn();
      //cout << minl << endl;
    }
    dfs(minl, minl + 1);
  } else {
    dfs(l, r + 1);
  }
}
int main() {
  cin >> n >> in;
  dfs(0, 1);
  for (int i = 0; i < n; i++)
    cout << ans[i];
  cout << endl;
  return 0;
}
