/*************************************************************************
    > File Name: 6.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 15时18分18秒
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
typedef pair<ll, ll> P;
struct cmp {
  bool operator()(P a, P b) {
    if (a.first != b.first) {
      return a.first < b.first;
    } else {
      return a.second > b.second;
    }
  }
};
priority_queue<P, vector<P>, cmp> ps;
int n, m;
int main() {
  cin >> n >> m;
  P wn;
  cin >> wn.first >> wn.second;
  ll a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ps.push(P(a, b));
  }
  for (int i = 0; i < m; i++) {
    string in;
    cin >> in;
    if (in[0] == 'm') {
      ps.pop();
    } else {
      cin >> a >> b;
      ps.push(P(a, b));
    }
  }
  int ans = 0;
  while (!ps.empty()) {
    if (ps.top().first > wn.first || (ps.top().first == wn.first && ps.top().second < wn.second)) {
      ans++;
      ps.pop();
    } else {
      break;
    }
  }
  cout << ++ans << endl;
  return 0;
}
