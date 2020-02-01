/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月02日 星期日 20时03分41秒
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
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int nmax = 3e5 + 5;
int n;
vector<P> a_b, b_a;
map<P, int> mapp;
bool cmpa_b(P a, P b) {
  return a.second < b.second;
}
bool cmpb_a(P a, P b) {
  return a.first > b.first;
}
int main() {
  iofuck;
  cin >> n;
  int a, b;
  int mark = 0;
  int marka_b = 0;
  int markb_a = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a > b) {
      a_b.push_back(P(a, b));
      marka_b++;
      mapp[P(a, b)] = ++mark;
    } else {
      markb_a++;
      b_a.push_back(P(a, b));
      mapp[P(a, b)] = ++mark;
    }
  }
  sort(a_b.begin(), a_b.end(), cmpa_b);
  sort(b_a.begin(), b_a.end(), cmpb_a);
  if (marka_b > markb_a) {
    cout << marka_b << endl;
    for (auto tmp: a_b) {
      cout << mapp[tmp] << " ";
    }
  } else {
    cout << markb_a << endl;
    for (auto tmp: b_a) {
      cout << mapp[tmp] << " ";
    }
  }
  /*
    cout << "-----------" << endl;
    for(auto tmp : a_b){
        cout << tmp.first << " " << tmp.second << endl;
    }
    cout << "-----------" << endl;
    for(auto tmp : b_a){
        cout << tmp.first << " " << tmp.second << endl;
    }
    */
  return 0;
}
