// Author : Wqr_
// Time : 19/09/28
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttl(x) cout << "#" << (x) << "#" << endl;
#define ttt(x) cout << "#" << (x) << "#";
#define ttn cout << "####" << endl;
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 10;
int n, m, a[nmax], x[nmax];
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> m;
  int in;
  for (int i = 0; i < m; i++) {
    cin >> in;
    int it = lower_bound(a, a + n, in) - a;
    if (it != n) {
      cout << a[it] << endl;
    } else {
      cout << "Dr. Samer cannot take any offer :(." << endl;
    }
  }
  return 0;
}