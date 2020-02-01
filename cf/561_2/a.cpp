/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月17日 星期五 22时54分30秒
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
const int MAXN = 200200;
int n;
int nums[300];
int s(int in) {
  return (in * (in - 1)) / 2;
}
int main() {
  cin >> n;
  string in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    nums[(int)in[0]]++;
  }
  int ans = 0;
  for (int i = 0; i < 300; i++) {
    int tmp = nums[i] / 2;
    ans += s(tmp);
    ans += s(nums[i] - tmp);
  }
  cout << ans << endl;
  return 0;
}
