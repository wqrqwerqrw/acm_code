/*************************************************************************
    > File Name: 3.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 19时43分23秒
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
int main() {
  iofuck;
  int T;
  cin >> T;
  while (T--) {
    string s;
    string t;
    cin >> s >> t;
    if (s.length() - t.length() != 2) {
      cout << 0 << endl;
      continue;
    }
    int i = 0, j = 0;
    for (; i < t.length() && j < s.length();) {
      if (t[i] == s[j]) {
        i++;
        j++;
      } else {
        j++;
      }
    }
    if (i == t.length())
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
