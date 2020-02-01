// Author : Wqr_
// Time : 2019年08月27日 星期二 20时38分19秒

#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int n;
const int maxn = 25;
vector<string> str(maxn);
int ans = -1;
int ch[maxn][maxn];
bool vis[maxn];
char first;

int getchong(string a, string b) {
  int ret = 0;
  int a_it = max(int(a.size() - b.size()), 0), b_it = 0;
  for (; a_it < a.size();) {
    if (a[a_it] == b[b_it])
      ret++, a_it++, b_it++;
    else
      a_it++, b_it = 0, ret = 0;
  }
  if (ret == a.size() || ret == b.size()) ret = -1;
  return ret;
}

void getch() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ch[i][j] = getchong(str[i], str[j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ch[i][j] << "   ";
    }
    cout << endl;
  }
}

void dfs(int chr, int num) {
  vis[chr] = 1;
  ans = max(num, ans);
  for (int i = 0; i < n; i++) {
    if (!vis[i] && ch[chr][i] != -1) {
      int next = num + str[i].size() - ch[chr][i];
      dfs(i, next);
    }
  }
  vis[chr] = 0;
}

int main() {
  iofuck;
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  cin >> first;
  getch();
  for (int i = 0; i < n; i++) {
    if (str[i][0] == first)
      dfs(i, str[i].size());
  }
  cout << ans + 1 << endl;
  return 0;
}
