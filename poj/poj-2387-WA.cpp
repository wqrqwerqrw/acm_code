/**********************************************************
    > File Name : 2387.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 16 20:09:34
**********************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#define INF 99999999
using namespace std;
struct edgee {
  int from, to, cost;
} edge[2004];
int d[2004];
int n, t;
int mind[2004];
void ford(int in) {
  for (int i = 0; i < n + 1; i++) {
    d[i] = INF;
  }
  d[in] = 0;
  while (true) {
    bool update = false;
    for (int i = 0; i < t; i++) {
      if (d[edge[i].from] != INF && d[edge[i].to] > d[edge[i].from] + edge[i].cost) {
        d[edge[i].to] = d[edge[i].from] + edge[i].cost;
        update = false;
      }
      if (d[edge[i].to] != INF && d[edge[i].from] > d[edge[i].to] + edge[i].cost) {
        d[edge[i].from] = d[edge[i].to] + edge[i].cost;
        update = false;
      }
    }
    if (!update) break;
  }
}
int main() {
  int fp, tp, costp;
  while (cin >> n >> t) {
    for (int i = 0; i < t; i++) {
      scanf("%d %d %d", &fp, &tp, &costp);
      edge[i].from = fp;
      edge[i].to = tp;
      edge[i].cost = costp;
    }
    ford(1);
    cout << d[n] << endl;
  }
  return 0;
}
