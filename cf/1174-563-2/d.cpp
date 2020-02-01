/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 23时39分24秒
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
int n, x;
int main() {
  cin >> n >> x;
  for (int i = 1; i <= pow(2, n); i++) {
    cout << (n ^ x) << " ";
  }
  return 0;
}
