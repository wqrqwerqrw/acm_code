// Author : Wqr_
// Time : 19/09/25
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttt cout << "<><><>" << endl;
using namespace std;
typedef long long ll;
struct point {
  double x, y, r;
  bool vis;
} ps[10];
int n, x, y, x_, y_;
int maxx, maxy, minx, miny;
double ans = -1;
double gitdis(int a_, int b_) {
  point& a = ps[a_];
  point& b = ps[b_];
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
void solve() {
  double tmp = 0;
  for (int i = 0; i < n; i++) {
    tmp += M_PI * ps[i].r * ps[i].r;
  }
  ans = max(ans, tmp);
}
void dfs(int in, int num) {
  point& now = ps[in];
  now.r = min(now.r, abs(now.x - minx));
  now.r = min(now.r, abs(now.x - maxx));
  now.r = min(now.r, abs(now.y - miny));
  now.r = min(now.r, abs(now.y - maxy));
  for (int i = 0; i < n; i++) {
    if (i == in) continue;
    if (ps[i].vis) {
      now.r = min(now.r, gitdis(in, i) - ps[i].r);
    }
  }
  if (now.r < 0) now.r = 0;
  if (num == n) {
    solve();
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!ps[i].vis) {
      ps[i].vis = 1;
      ps[i].r = INF;
      dfs(i, num + 1);
      ps[i].vis = 0;
      ps[i].r = INF;
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  //std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  cin >> n;
  cin >> x >> y >> x_ >> y_;
  maxx = max(x, x_);
  minx = min(x, x_);
  maxy = max(y, y_);
  miny = min(y, y_);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].x >> ps[i].y;
  }
  for (int i = 0; i < n; i++) {
    ps[i].vis = 1;
    ps[i].r = INF;
    dfs(i, 1);
    ps[i].r = INF;
    ps[i].vis = 0;
  }
  double anss = (maxx - minx) * (maxy - miny) - ans;
  printf("%.0f", anss);
  return 0;
}