// Author : Wqr_
// Time : 19/09/14
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 10;
ll n, k[nmax], ans[nmax];
bool iff;
stack<int> a;
stack<int> b;
stack<int> c;
void sync() {
  int tmp = b.top();
  b.pop();
  while (!b.empty() && tmp == b.top()) {
    tmp++;
    b.pop();
  }
  b.push(tmp);
}
void init() {
  while (!a.empty()) a.pop();
  while (!b.empty()) b.pop();
  while (!c.empty()) c.pop();
}
int main() {
  for (int i = 0; i < 3; i++) {
    b.push(0);
    sync();
  }
  cout << b.top();
  return 0;
}
