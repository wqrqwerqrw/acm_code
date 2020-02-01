// Author : Wqr_
// Time : 2019年06月11日 星期二 20时20分25秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 500 + 5;
int a1, b1, c1;
int a2, b2, c2;
string zh;
int dp[nmax][nmax][nmax][2];
int main() {
  iofuck;
  cin >> a1 >> b1 >> c1;
  cin >> a2 >> b2 >> c2;
  cin >> zh;
  //dp[1][a1][b1][0] = ;
  for (int i = 0; i < zh.length(); i++) {
    if (zh[i] == '1') {
    } else if (zh[i] == '0') {
    }
  }
  return 0;
}
