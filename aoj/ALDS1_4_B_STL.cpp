/*************************************************************************
    > File Name: ALDS1_4_B_STL.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Feb 28 20:37:46 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int A[1000000], n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q, k, sum = 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> k;
    if (*lower_bound(A, A + n, k) == k) sum++;
  }
  cout << sum << endl;
  return 0;
}
