/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月14日 星期二 22时48分55秒
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
#define MAX_N 200100
using namespace std;
typedef long long ll;
int n;
int a[MAX_N];
int main() {
  cin >> n;
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    q.push(a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int num = q.top();
    q.pop();
    while (num < i + 1 && !q.empty()) {
      num = q.top();
      q.pop();
    }
    if (num >= i + 1) ans++;
    if (q.empty()) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
