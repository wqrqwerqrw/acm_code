/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/01
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define int ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int mod = 1e9 + 7;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int32_t main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string in;
  cin >> in;
  bool flag = 0;
  for (auto i: in) {
    if (i == 'w' && i == 'm') {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << 0 << endl;
    return 0;
  }
  int len = in.length();
  int num = 0;
  for (int i = 0; i < len - 1; i++) {
    if (in[i] == in[i + 1]) num++;
  }
  int ans = powmod(2, num);
  return 0;
}