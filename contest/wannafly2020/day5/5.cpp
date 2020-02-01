// Wqr_
// Time : 20/01/16
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
const int N = 300 + 10;
int tmp[N];
int a[N];
int b[4];
int n;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < 4; i++) cin >> b[i];
  set<vector<int>> sett;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((a[i] == a[j]) ==)
    }
  }
  /*
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] == a[j]) != (b[0] == b[1])) continue;
            for (int k = j + 1; k < n; k++) {
                if ((a[j] == a[k]) != b[1] == b[2]) continue;
                vector<int> tmpv = {a[i], a[j], a[k]};
                if(sett.count(tmpv)) continue;
                sett.insert(tmpv);
                tmp[k]++;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] == a[j]) == (b[2] == b[3])) {
                ans += tmp[i];
            }
        }
    }
    */
  cout << ans << endl;
  return 0;
}