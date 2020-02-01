// Author : Wqr_
// Time : 19/09/21
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n, k;
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    int u, v;
    for (int i = 0; i < n; i++) {
      cin >> u >> v;
      u--, v--;
    }
  }
  return 0;
}