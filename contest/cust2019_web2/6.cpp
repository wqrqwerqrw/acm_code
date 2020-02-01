/*************************************************************************
    > File Name: 6.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 15时28分25秒
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
int main() {
  cin >> n;
  map<string, int> mapp;
  string in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    mapp[in]++;
  }
  int ans = 0;
  for (auto tmp: mapp) {
    if (tmp.second >= 9) ans += tmp.second / 9;
  }
  cout << ans << endl;
  for (auto tmp: mapp) {
    if (tmp.second >= 9) {
      for (int i = 0; i < tmp.second / 9; i++) {
        cout << tmp.first << endl;
      }
    }
  }
  return 0;
}
