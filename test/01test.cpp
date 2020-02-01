/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/12
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  vector<vector<int> > v;
  vector<int> G[100];
  vi tmp;
  tmp.push_back(1);
  v.push_back(tmp);
  for (auto i: v) {
    for (auto j: i) {
      cout << j << endl;
    }
  }
  return 0;
}