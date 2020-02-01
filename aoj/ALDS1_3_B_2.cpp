/*************************************************************************
    > File Name: ALDS1_3_B_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Nov 12 19:22:00 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define LEN 10005
using namespace std;
struct dui {
  string name;
  int t;
} Q[LEN];
int head, tail, n;
void enqueue(dui in) {
  Q[tail] = in;
  tail = (tail + 1) % LEN;
}
dui dequeue() {
  dui out = Q[head];
  head = (head + 1) % LEN;
  return out;
}
int min(int a, int b) {
  return a < b ? a : b;
}
int main() {
  int tneed;
  int timeZong;
  cin >> n >> tneed;
  for (int i = 0; i < n; i++) {
    cin >> Q[i].name >> Q[i].t;
  }
  head = 0;
  tail = n;
  while (head != tail) {
    dui x = dequeue();
    int time = min(tneed, u.t);
    u.t -= time;
    timeZong += time;
  }
}
