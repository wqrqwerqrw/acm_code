// Wqr_
// Time : 20/01/22
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), g(n), f(n), s(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    g[i] = f[i] = 1;
  }
  for(int i = n - 1; i >= 0; i--){
    for(int j = i + 1; j < n; j++){
      if(a[i] > a[j] && f[i] < f[j] + 1) f[i] = f[j] + 1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      if(a[i] > a[j] && g[i] < g[j] + 1) g[i] = g[j] + 1;
    }
  }
  int maxn = 0;
  for(int i = 0; i < n; i++){
    maxn = max(maxn, f[i] + g[i] - 1);
  }
  cout << n - maxn;
  return 0;
}