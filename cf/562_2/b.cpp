/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月26日 星期日 23时44分16秒
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
typedef pair<int, int> P;
P ps[300300];
int n, m;
bool cmp(const P &a, const P &b) {
  return a.second > b.second;
}
int main() {
  cin >> n >> m;
  int a, b;
  map<int, int> mapp;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    ps[i].first = a;
    ps[i].second = b;
    mapp[a]++;
    mapp[b]++;
  }
  vector<P> v(mapp.begin(), mapp.end());
  sort(v.begin(), v.end(), cmp);
  bool flag = 0;
  for (auto tmp: v) {
    if (tmp.second > (m / 2)) {
    }
  }
  return 0;
}
