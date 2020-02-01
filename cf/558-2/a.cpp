/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月12日 星期日 19时31分40秒
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
int n, m;
int ans[1010];
void solve() {
  for (int i = 1; i <= n / 2; i++) {
    ans[i] = i;
    ans[n - i] = i;
  }
  cout << ans[m] << endl;
}
int main() {
  while (cin >> n >> m) {
    if (m == 0) {
      cout << 1 << endl;
      return 0;
    }
    solve();
  }
  return 0;
}
