/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/18
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
  //std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  string in;
  cin >> in;
  bool flag = 1;
  for (int i = 0; i < in.length(); i++) {
    if (i % 2) {
      if (in[i] != 'L' && in[i] != 'U' && in[i] != 'D') flag = 0;
    } else {
      if (in[i] != 'R' && in[i] != 'U' && in[i] != 'D') flag = 0;
    }
  }
  if (flag)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}