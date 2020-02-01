/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/13
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define int ll
const int N = 1e5 + 7;
vector<int> G[N];

int32_t main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int tmp;
  for (int i = 2; i <= n; i++) {
    cin >> tmp;
    G[tmp].push_back(i);
  }
  d for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}