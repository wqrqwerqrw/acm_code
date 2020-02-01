/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/20
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
const int nmax = 300 + 30;
int dis1[nmax][nmax], dis2[nmax][nmax];
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m, l;
  cin >> n >> m >> l;
  int a, b, c;
  memset(dis1, inf, sizeof(dis1));
  memset(dis2, inf, sizeof(dis2));
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    dis1[a][b] = c;
    dis1[b][a] = c;
  }
  for (int i = 0; i < n; ++i) {
    dis1[i][i] = dis2[i][i] = 0;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dis1[i][j] = min(dis1[i][j], dis1[i][k] + dis1[k][j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dis1[i][j] <= l) {
        dis2[i][j] = 1;
        dis2[j][i] = 1;
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; j++) {
        dis2[i][j] = min(dis2[i][j], dis2[i][k] + dis2[k][j]);
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    --a, --b;
    if (dis2[a][b] == inf) dis2[a][b] = 0;
    cout << (dis2[a][b] - 1) << endl;
  }
  return 0;
}