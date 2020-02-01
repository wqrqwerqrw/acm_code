/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/06
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b) {
      map<char, int> mapp;
      for (auto i: a) mapp[i]++;
      bool flag = 0;
      for (auto i: mapp) {
        if (i.second >= 2) {
          flag = 1;
        }
      }
      if (flag) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      vector<int> v;
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
          v.push_back(i);
        }
      }
      if (v.size() != 2) {
        cout << "NO" << endl;
        continue;
      } else {
        if (a[v[0]] != a[v[1]] || b[v[0]] != b[v[1]]) {
          cout << "NO" << endl;
          continue;
        }
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}