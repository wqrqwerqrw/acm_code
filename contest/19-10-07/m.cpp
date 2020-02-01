// Author : Wqr_
// Time : 19/10/07
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
ll n;
ll pr[5];
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int kase = 1; kase <= t; kase++) {
    ll tot = 0;
    for (int i = 0; i < 5; i++) {
      cin >> pr[i];
    }
    cin >> n;
    int id;
    for (int i = 0; i < n; i++) {
      cin >> id;
      if (1 <= id && id <= 48) {
        tot += pr[0];
      } else if (48 < id && id <= 56) {
        tot += pr[1];
      } else if (56 < id && id <= 60) {
        tot += pr[2];
      } else if (60 < id && id <= 62) {
        tot += pr[3];
      } else if (62 < id && id <= 63) {
        tot += pr[4];
      }
    }
    cout << "Case #" << kase << ": " << (tot * 10000) << endl;
  }
  return 0;
}