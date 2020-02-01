// Author : Wqr_
// Time : 19/09/13
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct test {
  int a, b;
  bool operator<(const test &in) const {
    return a > in.a;
  }
};
set<test> sett;
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  sett.insert(test{1, 4});
  sett.insert(test{2, 3});
  sett.insert(test{3, 2});
  sett.insert(test{4, 1});
  for (auto i: sett) cout << i.a << " ";
  return 0;
}