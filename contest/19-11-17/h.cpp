#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
class Point {
 public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point a) {
    return Point(a.x + x, a.y + y);
  }
  Point operator-(Point a) {
    return Point(x - a.x, y - a.y);
  }
  bool operator<(const Point &a) const {
    if (x == a.x)
      return y < a.y;
    return x < a.x;
  }
};
double det(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}
double dot(Point a, Point b) {
  return a.x * b.x + a.y * b.y;
}
bool isclock(Point p0, Point p1, Point p2) {
  Point a = p1 - p0;
  Point b = p2 - p0;
  if (det(a, b) < -eps) return true;
  return false;
}
double getDistance(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
vector<Point> andrewScan(vector<Point> s) {
  vector<Point> u, l;
  if (s.size() < 3) return s;
  sort(s.begin(), s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);
  for (int i = 2; i < s.size(); i++) {
    for (int n = u.size(); n >= 2 && isclock(u[n - 2], u[n - 1], s[i]) != true; n--) {
      u.pop_back();
    }
    u.push_back(s[i]);
  }
  for (int i = s.size() - 3; i >= 0; i--) {
    for (int n = l.size(); n >= 2 && isclock(l[n - 2], l[n - 1], s[i]) != true; n--) {
      l.pop_back();
    }
    l.push_back(s[i]);
  }
  for (int i = 1; i < u.size() - 1; i++) l.push_back(u[i]);
  return l;
}
int cmp(double x) {
  if (fabs(x) < eps) return 0;
  if (x > 0) return 1;
  return -1;
}
bool PointOnSegment(Point p, Point s, Point t) {
  return cmp(det(p - s, t - s)) == 0 && cmp(dot(p - s, p - t)) <= 0;
}
struct polygon {
  int n;
  vector<Point> a;
  polygon(vector<Point> in) {
    for (auto i: in) {
      a.push_back(i);
    }
    a.push_back(in.front());
    n = in.size();
  }
  bool Point_In(Point t) {
    int num = 0, i, d1, d2, k;
    for (int i = 0; i < n; i++) {
      if (PointOnSegment(t, a[i], a[i + 1])) return 0;
      k = cmp(det(a[i + 1] - a[i], t - a[i]));
      d1 = cmp(a[i].y - t.y);
      d2 = cmp(a[i + 1].y - t.y);
      if (k > 0 && d1 <= 0 && d2 > 0) num++;
      if (k < 0 && d2 <= 0 && d1 > 0) num--;
    }
    return num != 0;
  }
};
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int kase = 1; kase <= t; kase++) {
    cout << "Case " << kase << endl;
    int c, p;
    cin >> c >> p;
    double a, b;
    vector<Point> ps;
    for (int i = 0; i < c; i++) {
      cin >> a >> b;
      ps.push_back(Point(a, b));
    }
    vector<Point> anstmp = andrewScan(ps);
    vector<Point> ans;
    for (int i = anstmp.size() - 1; i >= 0; i--) {
      ans.push_back(anstmp[i]);
    }
    int minit = 0;
    Point minP(1e5, 1e5);
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] < minP) {
        minit = i;
        minP = ans[i];
      }
    }
    for (int i = 0; i < ans.size(); i++) {
      int cur = (i + minit) % ans.size();
      cout << ans[cur].x << " " << ans[cur].y << endl;
    }
    cout << ans[minit].x << " " << ans[minit].y << endl;
    polygon pol(ans);
    for (int i = 0; i < p; i++) {
      cin >> a >> b;
      if (pol.Point_In(Point(a, b))) {
        cout << a << " " << b << " is unsafe!" << endl;
      } else {
        cout << a << " " << b << " is safe!" << endl;
      }
    }
    if (kase != t) cout << endl;
  }
  return 0;
}