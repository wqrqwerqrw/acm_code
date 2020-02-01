/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月15日 星期三 22时56分29秒
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
#define MAXN 500500
using namespace std;
typedef long long ll;
int n, m;
int par[MAXN];
int hi[MAXN];
int num[MAXN];  //储存集合元素的个数
void init(int n) {
  for (int i = 0; i < n; i++) {
    num[i] = 1;
    par[i] = i;
    hi[i] = 0;
  }
}
int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (hi[x] < hi[y]) {
    par[x] = y;
    num[y] += num[x];  //合并
  } else {
    par[y] = x;
    if (hi[x] == hi[y]) hi[x]++;
    num[x] += num[y];  //合并
  }
}
bool same(int x, int y) {
  return find(x) == find(y);
}
int book[500500];
bool mark[500500];
int main() {
  cin >> n >> m;
  init(n);
  for (int i = 0; i < m; i++) {
    int ge;
    int in[MAXN];
    scanf("%d", &ge);
    int last, now;
    for (int j = 0; j < ge; j++) {
      //if(j) last = now;
      scanf("%d", in + j);
      /*
            if(j){
                if(mark[last - 1] && mark[now - 1]) continue;
                unite(last - 1, now - 1);
                mark[last - 1] = 1;
                mark[now - 1] = 1;
            }
            */
    }
    for (int j = 0; j < ge - 1; j++) {
      int a = in[j] - 1;
      int b = in[j + 1] - 1;
      unite(a, b);
    }
  }
  for (int i = 0; i < n; i++) {
    int x = find(i);
    printf("%d ", num[x]);
  }
  return 0;
}
