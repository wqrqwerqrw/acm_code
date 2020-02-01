/*************************************************************************
    > File Name: ALDS1_4_B.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Feb 28 20:19:01 2019
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
int search(int key) {
  int left = 0;
  int right = n;
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (key == A[mid])
      return mid;
    if (key > A[mid])
      left = mid + 1;
    else if (key < A[mid])
      right = mid;
  }
  return 0;
}
int main() {
  int i, q, k, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> k;
    if (search(k)) sum++;
  }
  cout << sum;
  return 0;
}
