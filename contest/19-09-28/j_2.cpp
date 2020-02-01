// Author : Wqr_
// Time : 19/09/28
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttl(x) cout << "#" << (x) << "#" << endl;
#define ttt(x) cout << "#" << (x) << "#";
#define ttn cout << "####" << endl;
using namespace std;
typedef long long ll;
int n, m;
typedef vector<int> vec;
vector<vec> in(20);
int chong[20][20];
int ch(vec& a, vec& b) {
  int la = a.size(), lb = b.size();
  int ret = 0, ita = max(la - lb, 0), itb = 0;
  while (ita < la) {
    if (a[ita] == b[itb])
      ita++, itb++, ret++;
    else
      ita++, itb = 0, ret = 0;
  }
  return ret;
}
bool vis[20];
int ans = INF;
void dfs(int now, int cur, int num) {
  if (cur > ans) return;
  if (num == n) ans = min(ans, cur);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      dfs(i, cur + in[i].size() - chong[now][i], num + 1);
      vis[i] = 0;
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  double start = clock();
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  memset(vis, 0, sizeof(vis));
  int next;
  for (int i = 0; i < n; i++) {
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> next;
      in[i].push_back(next);
    }
  }
  sort(in.begin(), in.begin() + n, [](vec& a, vec& b) { return a.size() < b.size(); });
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        chong[i][j] = 0;
      else
        chong[i][j] = ch(in[i], in[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    vis[i] = 1;
    dfs(i, in[i].size(), 1);
    vis[i] = 0;
  }
  cout << ans << endl;
  return 0;
}