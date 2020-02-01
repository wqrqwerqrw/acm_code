/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Nov 16 22:51:10 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
  int n;
  cin >> n;
  int in[200001];
  int out[n];
  int num = 0;
  int max = 0;
  int maxnum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &in[i]);
    if (in[i] > max) {
      max = in[i];
      maxnum = i;
    }
  }
  for (int i = 0; i < n; i++) {
    int t = in[i];
    in[i] = 0;
    int fuck = 0;
    bool flag = false;
    int maxt = max;
    int maxnumt = maxnum;
    if (i == maxnum) {
      flag = true;
      max = 0;
      maxnum = 0;
      for (int i = 0; i < n; i++) {
        if (in[i] > max) {
          max = in[i];
          maxnum = i;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (j != maxnum) {
        fuck += in[j];
      }
    }
    if (fuck == max) out[num++] = i;
    in[i] = t;
    if (flag) {
      max = maxt;
      maxnum = maxnumt;
    }
  }
  cout << num << endl;
  for (int i = 0; i < num; i++) {
    if (i) printf(" ");
    printf("%d", out[i] + 1);
  }
  return 0;
}
