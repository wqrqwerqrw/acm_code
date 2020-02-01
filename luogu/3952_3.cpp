// Author : Wqr_
// Time : 2019年07月20日 星期六 19时14分30秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
map<char, bool> mapp;
list<int> s_n, s_b, cs;
bool ife, ifb;
int w, ans;
void init() {
  mapp.clear();
  s_n.clear();
  s_b.clear();
  cs.clear();
  ife = 0, ifb = 0, ans = 0;
}
void f() {
  char i, x[5], y[5];
  cin >> i >> x >> y;
  if (mapp[i]) ife = 1;
  mapp[i] = 1, cs.push_back(i);
  int x_int = 0, y_int = 0;
  if (isdigit(x[0])) sscanf(x, "%d", &x_int);
  if (isdigit(y[0])) sscanf(y, "%d", &y_int);
  if (x[0] == 'n' && y[0] == 'n') ifb ? s_b.push_back(0) : s_n.push_back(0);
  if (x[0] == 'n' && y_int) ifb = 1, s_n.push_back(0);
  if (x_int && y[0] == 'n') ifb ? s_b.push_back(1) : s_n.push_back(1);
  if (x_int && y_int) {
    if (x_int > y_int) ifb = 1, s_n.push_back(0);
    if (x_int <= y_int) ifb ? s_b.push_back(0) : s_n.push_back(0);
  }
}
void e() {
  auto all = [](int ret = 0) {
    for (auto i: s_n) ret += i;
    return ret;
  }();
  ans = max(ans, all);
  if (!s_b.empty())
    s_b.pop_back();
  else if (!s_n.empty())
    s_n.pop_back();
  else
    ife = 1;
  if (!cs.empty()) mapp[cs.back()] = 0, cs.pop_back();
  if (s_b.empty() && s_n.empty()) {
    mapp.clear();
    ifb = 0;
  }
}
void solve() {
  init();
  int l;
  char o[10], ope;
  scanf("%d %s", &l, o);
  if (o[2] == '1')
    w = 0;
  else
    sscanf(&o[4], "%d", &w);
  for (int i = 0; i < l; i++) {
    cin >> ope;
    (ope == 'F') ? f() : e();
  }
  if (ife || !s_n.empty() || !s_b.empty())
    printf("ERR\n");
  else
    (ans == w) ? printf("Yes\n") : printf("No\n");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
