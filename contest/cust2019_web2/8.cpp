/*************************************************************************
    > File Name: 8.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 13时58分34秒
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
ll n, m;
//ll bao[10010];
struct cmp {
  bool operator()(P a, P b) {
    if (a.first != b.first) {
      return a.first > b.first;
    } else {
      return a.second > b.second;
    }
  }
};
priority_queue<P, vector<P>, cmp> er;
priority_queue<ll, vector<ll>, greater<ll> > bao;
int main() {
  cin >> n >> m;
  ll ina, inb;
  for (ll i = 0; i < n; i++) {
    scanf("%ld %ld", &ina, &inb);
    er.push(P(ina, inb));
  }
  /*
    while(!er.empty()){
        cout << er.top().first << " " << er.top().second << endl;
        er.pop();
    }
    cout << "------" << endl;
    */
  for (ll i = 0; i < m; i++) {
    scanf("%ld", &ina);
    bao.push(ina);
  }
  ll ans = 0;
  while (!bao.empty() && !er.empty()) {
    if (bao.top() >= er.top().first && bao.top() <= er.top().second) {
      bao.pop();
      er.pop();
      ans++;
    } else if (bao.top() < er.top().first) {
      bao.pop();
    } else if (bao.top() > er.top().second) {
      er.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
