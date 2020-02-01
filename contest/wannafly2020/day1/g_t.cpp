#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define gc getchar
#define pc putchar
#define cs const

inline double getdb() {
  re double x, y = 1.0;
  re char c;
  re bool f = 0;
  while (!isdigit(c = gc()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = gc())) x = (x * 10) + (c ^ 48);
  if (c != '.') return f ? -x : x;
  while (isdigit(c = gc())) x += (y /= 10) * (c ^ 48);
  return f ? -x : x;
}

cs int N = 1005;
cs double PI = acos(-1.0), eps = 1e-7;
struct Point {
  double x, y;
  int id;
  Point(cs double &_x = 0, cs double &_y = 0, cs int &_id = 0) : x(_x), y(_y), id(_id) {}
  friend Point operator+(cs Point &a, cs Point &b) { return Point(a.x + b.x, a.y + b.y); }
  friend Point operator-(cs Point &a, cs Point &b) { return Point(a.x - b.x, a.y - b.y); }
  friend Point operator*(cs Point &a, cs double &b) { return Point(a.x * b, a.y * b); }
  friend Point operator/(cs Point &a, cs double &b) { return Point(a.x / b, a.y / b); }
  friend double operator*(cs Point &a, cs Point &b) { return a.x * b.y - b.x * a.y; }
  friend double dot(cs Point &a, cs Point &b) { return a.x * b.x + a.y * b.y; }
  double norm() cs { return sqrt(dot(*this, *this)); }
  friend Point rotate(cs Point &a, cs double &rad) { return Point(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad)); }
  Point reflect() cs { return Point(-y, x) / norm(); }
} p[N * N * 2];
int n;
inline double dist(cs Point &a, cs Point &b) {
  return (a - b).norm();
}

inline double angle(cs Point &a, cs Point &b) {
  return acos(dot(a, b) / a.norm() / b.norm());
}

int tot;
inline int sign(cs double &x) {
  return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1);
}

inline bool cmp(cs Point &a, cs Point &b) {
  return sign((a - p[1]) * (b - p[1])) == 0 ? (a - p[1]).norm() < (b - p[1]).norm() : sign((a - p[1]) * (b - p[1])) > 0;
}

inline bool check(cs Point &a);

inline void convex_hull(int m) {
  for (int re i = 2; i <= m; ++i)
    if (sign(p[i].x - p[1].x) < 0 || (sign(p[i].x - p[1].x) == 0 && sign(p[i].y - p[1].y) > 0)) swap(p[1], p[i]);
  sort(p + 2, p + m + 1, cmp);
  n = 1;
  for (int re i = 2; i <= m; ++i) {
    while (n >= 2 && sign((p[n] - p[n - 1]) * (p[i] - p[n - 1])) <= 0) --n;
    p[++n] = p[i];
  }
  m = n;
  n = 0;
  for (int re i = 1; i <= m; ++i) {
    if (check(p[i])) p[++n] = p[i];
  }
}

struct Circle {
  Point o;
  double r;
  int id;
  Point radius() cs { return Point(r, 0); }
  bool in(cs Point &a)cs {
    return dist(a, o) < r + eps;
  }
} c[N];

inline void work(Circle a, Circle b) {
  if (a.r > b.r) swap(a, b);
  double D = dist(a.o, b.o);
  double d = b.r - a.r;
  double rad = atan2(a.o.y - b.o.y, a.o.x - b.o.x);
  Point k = rotate(a.radius(), rad + acos(d / D));
  p[++n] = a.o + k;
  p[n].id = a.id;
  k = rotate(a.radius(), rad - acos(d / D));
  p[++n] = a.o + k;
  p[n].id = a.id;
  k = rotate(b.radius(), rad + acos(d / D));
  p[++n] = b.o + k;
  p[n].id = b.id;
  k = rotate(b.radius(), rad - acos(d / D));
  p[++n] = b.o + k;
  p[n].id = b.id;
}

inline void build(int m) {
  n = 0;
  for (int re i = 1; i <= m; ++i)
    for (int re j = i + 1; j <= m; ++j) work(c[i], c[j]);
}

double ans;
inline void solve() {
  for (int re i = 1; i <= n; ++i) {
    if (p[i].id == p[i % n + 1].id) {
      int id = p[i].id;
      double rad = angle(p[i] - c[id].o, p[i % n + 1] - c[id].o);
      if ((p[i] - c[id].o) * (p[i % n + 1] - c[id].o) < eps) rad = 2 * PI - rad;
      ans += rad * c[id].r;
    } else
      ans += dist(p[i], p[i % n + 1]);
  }
  printf("%.10f", ans);
}

inline bool check(cs Point &a) {
  for (int re i = 1; i <= tot; ++i) {
    if (i != a.id)
      if (c[i].in(a)) return false;
  }
  return true;
}

bool ban[N];
signed main() {
  int t;
  scanf("%d", &n);
  if (n == 0) return puts("0.00000000"), 0;
  for (int re i = 1; i <= n; ++i) {
    c[i].o.x = getdb();
    c[i].o.y = getdb();
    c[i].r = getdb() + 10;
  }
  for (int re i = 1; i <= n; ++i) {
    if (!ban[i])
      for (int re j = 1; j <= n; ++j) {
        if (i == j || ban[j]) continue;
        if (dist(c[i].o, c[j].o) > c[i].r) continue;
        if (dist(c[i].o, c[j].o) < eps) {
          if (c[j].r <= c[i].r) ban[j] = true;
          continue;
        }
        if (dist(c[i].o, c[j].o) + c[j].r <= c[i].r) ban[j] = true;
      }
  }
  {
    int cnt = 0;
    for (int re i = 1; i <= n; ++i)
      if (!ban[i]) c[++cnt] = c[i], c[cnt].id = cnt;
    tot = n = cnt;
  }
  if (n == 1) {
    printf("%.10f", 2 * PI * c[1].r);
    return 0;
  }
  build(n);
  convex_hull(n);
  solve();
  return 0;
}