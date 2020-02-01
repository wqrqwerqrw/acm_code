/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月12日 星期日 20时06分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
int a[101000];
int sum[101000][11];
void solve() {
  for (int i = n - 1; i >= 0; i--) {
    bool flag = 0;
    for (int j = 1; j <= 10; j++) {
      if (!sum[i][j]) continue;
      sum[i][j]--;
      /*
            bool mark[101000];
            memset(mark, 0, sizeof(mark));
            for(int k = 1; k <= 10; k++){
                if(!sum[i][k]) continue;
                mark[sum[i][k]] = 1;
            }
            int kkk = 0;
            for(int k = 1; k <= 10; k++){
                kkk += mark[k];
            }
            if(kkk == 1) {
                flag = 1;
                break;
            }
            */
      map<int, int> mapp;
      for (int k = 1; k <= 10; k++) {
        if (sum[i][k]) mapp[sum[i][k]] = 1;
      }
      int kkk = 0;
      for (auto m: mapp) {
        kkk += m.second;
      }
      if (kkk == 1) {
        flag = 1;
        break;
      }
      sum[i][j]++;
    }
    if (flag) {
      cout << i + 1 << endl;
      break;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (i) {
      for (int j = 1; j <= 10; j++) {
        sum[i][j] = sum[i - 1][j];
      }
    }
    sum[i][a[i]]++;
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  solve();
  return 0;
}
