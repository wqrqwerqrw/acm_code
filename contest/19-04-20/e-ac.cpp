/*************************************************************************
    > File Name: e.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 13时45分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool map[110][110];
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    memset(map, 0, sizeof(map));
    char in;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> in;
        if (in == '*')
          map[i][j] = 1;
        else
          map[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[i][j]) {
          cout << "*";
          continue;
        }
        int out = 0;
        int a, b;
        a = i - 1;
        b = j - 1;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        a = i - 1;
        b = j;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        a = i - 1;
        b = j + 1;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        a = i;
        b = j - 1;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        a = i;
        b = j + 1;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        a = i + 1;
        b = j - 1;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        a = i + 1;
        b = j;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        a = i + 1;
        b = j + 1;
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b]) out++;
        cout << out;
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
