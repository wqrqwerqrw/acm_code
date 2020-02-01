// Author : Wqr_
// Time : 19/09/18
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 3000 + 30;
int s[nmax], c[nmax];
int n, ans = INF;
int main() {
  iofuck;
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int j = 2; j <= n - 1; j++) {
    int min1 = INF, min2 = INF;
    int ansi, ansk;
    for (int i = 1; i < j; i++)
      if (s[i] < s[j] && c[i] + c[j] < min1) {
        min1 = c[i] + c[j], ansi = i;
      }
    for (int k = j + 1; k <= n; k++)
      if (s[j] < s[k] && c[j] + c[k] < min2) {
        min2 = c[j] + c[k], ansk = k;
      }
    if (min1 == INF || min2 == INF) continue;
    ans = min(ans, c[j] + c[ansi] + c[ansk]);
  }
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}