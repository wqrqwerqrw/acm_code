/*************************************************************************
    > File Name: d2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月16日 星期四 09时57分33秒
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
#define MAXN 200100
using namespace std;
typedef long long ll;
int n;
string in;
bool ans[MAXN];
int main() {
  cin >> n >> in;
  bool cr = 0;
  ans[0] = cr;
  for (int i = 1; i < n; i++) {
    if (in[i] == in[i - 1]) cr = !cr;
    ans[i] = cr;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
