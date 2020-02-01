/*************************************************************************
    > File Name: 5.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 15时44分48秒
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
ll modd[110];
int main() {
  int t;
  cin >> t;
  ll l, r, k;
  while (t--) {
    scanf("%ld %ld %ld", &l, &r, &k);
    for (ll i = l; i < l + k && i <= r; i++) {
      ll s = i % k;
      modd[s] = (r - i) / k + 1;
    }
    for (int i = 0; i < k; i++) {
      if (i) printf(" ");
      printf("%ld", modd[i]);
    }
    printf("\n");
  }
  return 0;
}
