/*************************************************************************
    > File Name: 4.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 14时42分05秒
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
int m;
string in;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> m;
    cin >> in;
    int out = 0;
    for (int i = 0; i < in.length(); i++) {
      int ans = 0;
      if (in[i] == '1') {
        for (int j = i; j < in.length(); j++) {
          if (in[j] != '1') {
            i = j;
            break;
          }
          ans++;
          if (j == in.length() - 1) {
            i = j;
            break;
          }
        }
        if (ans >= m) out++;
      }
    }
    cout << out << endl;
  }
  return 0;
}
