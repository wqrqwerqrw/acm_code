/*************************************************************************
    > File Name: 11292.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月25日 星期六 19时22分18秒
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
int dr[20010];
int pe[20010];
int main() {
  while (cin >> n >> m) {
    if (!n && !m) break;
    for (int i = 0; i < n; i++) {
      scanf("%d", dr + i);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", pe + i);
    }
    sort(dr, dr + n);
    sort(pe, pe + m);
    int cur = 0;
    int cost = 0;
    for (int i = 0; i < m; i++) {
      if (pe[i] >= dr[cur]) {
        cost += pe[i];
        if (++cur == n) break;
      }
    }
    if (cur < n)
      cout << "Loowater is doomed!" << endl;
    else
      cout << cost << endl;
  }
  return 0;
}
