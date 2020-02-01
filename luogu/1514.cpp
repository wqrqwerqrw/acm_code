// Author : Wqr_
// Time : 19/09/25
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttl(x) cout << "-" << (x) << "-" << endl;
#define ttt(x) cout << "-" << (x) << "-";
using namespace std;
typedef long long ll;
const int maxn = 500 + 50;
int n, m;
int mapp[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn], vis[maxn][maxn];
void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (abs(i) == abs(j)) continue;
      int nx = x + i;
      int ny = y + j;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (mapp[nx][ny] >= mapp[x][y]) continue;
      if (!vis[nx][ny]) dfs(nx, ny);
      l[x][y] = min(l[x][y], l[nx][ny]);
      r[x][y] = max(r[x][y], r[nx][ny]);
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mapp[i][j];
      l[i][j] = INF;
      r[i][j] = -1;
    }
  }
  for (int i = 0; i < m; i++) {
    l[n - 1][i] = r[n - 1][i] = i;
  }
  for (int i = 0; i < m; i++) {
    if (!vis[0][i])
      dfs(0, i);
  }
  bool flag = false;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (!vis[n - 1][i]) {
      flag = true;
      cnt++;
    }
  }
  if (flag) {
    cout << 0 << endl;
    cout << cnt << endl;
  } else {
    int left = 0;
    int ans = 0;
    while (left < m) {
      int right = 0;
      for (int i = 0; i < m; i++) {
        if (l[0][i] <= left) {
          right = max(right, r[0][i]);
        }
      }
      left = right + 1;
      ans++;
    }
    cout << 1 << endl;
    cout << ans << endl;
  }
  return 0;
}