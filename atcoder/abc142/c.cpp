/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/16
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
using pii = pair<int, int>;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  vector<pii> v;
  int n;
  cin >> n;
  int tmp;
  for (int i = 1; i <= n; i++) {
    cin >> tmp;
    v.push_back(make_pair(i, tmp));
  }
  sort(v.begin(), v.end(), [](pii a, pii b) { return a.second < b.second; });
  for (auto i: v) {
    cout << i.first << " ";
  }
  return 0;
}