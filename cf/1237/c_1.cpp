/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/16
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
const int nmax = 2000 + 10;
struct point {
  int x, y, z;
} ps[nmax];
double dis[nmax][nmax];
int n;
double ff(double in) {
  return in * in;
}
double dd(point& a, point& b) {
  return sqrt(ff(a.x - b.x) + ff(a.y - b.y) + ff(a.z - b.z));
}
bool book[nmax];
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    point& cur = ps[i];
    cin >> cur.x >> cur.y >> cur.z;
  }
  map<double, int> dmap[nmax];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      dmap[i][dd(ps[i], ps[j])] = j;
    }
  }
  for (int i = 0; i < n; i++) {
    if (book[i]) continue;
    int minit = 0;
    for (auto j: dmap[i]) {
      if (!book[j.second]) {
        minit = j.second;
        break;
      }
    }
    cout << i + 1 << " " << minit + 1 << endl;
    book[i] = 1;
    book[minit] = 1;
  }
  return 0;
}