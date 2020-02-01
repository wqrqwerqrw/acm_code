// Wqr_
// Time : 20/02/01
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
struct node {
  int x, y, step;
} st;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> mapp(n);
  vector<vector<int>> ans(n, vector<int>(n));
  vector<vector<int>> book(n, vector<int>(n));
  vector<int> dx = {2, 2, -2, -2, -1, 1, -1, 1};
  vector<int> dy = {-1, 1, -1, 1, -2, -2, 2, 2};
  for (auto &i: mapp) cin >> i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = -1;
      if (mapp[i][j] == 'M') {
        st.x = i;
        st.y = j;
        st.step = 0;
        ans[i][j] = 0;
      }
    }
  }
  auto bfs = [&]() {
    queue<node> q;
    q.push(st);
    book[st.x][st.y] = 1;
    while (!q.empty()) {
      node cur = q.front();
      q.pop();
      int x = cur.x, y = cur.y;
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (mapp[nx][ny] == 'X') continue;
        if (book[nx][ny]) continue;
        if (dx[i] == 2 && mapp[x + 1][y] == 'X') continue;
        if (dx[i] == -2 && mapp[x - 1][y] == 'X') continue;
        if (dy[i] == -2 && mapp[x][y - 1] == 'X') continue;
        if (dy[i] == 2 && mapp[x][y + 1] == 'X') continue;
        book[nx][ny] = 1;
        ans[nx][ny] = cur.step + 1;
        q.push({nx, ny, ans[nx][ny]});
      }
    }
  };
  bfs();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) cout << ' ';
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}