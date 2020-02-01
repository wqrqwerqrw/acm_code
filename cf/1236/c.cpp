/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/17
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
const int nmax = 300 + 10;
int n, ans[nmax][nmax];
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int cur = 1;
  for (int i = 0; i < n; i++) {
    if (i % 2)
      for (int j = 0; j < n; j++) ans[j][i] = cur++;
    else
      for (int j = n - 1; j >= 0; j--) ans[j][i] = cur++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}