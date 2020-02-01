/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/13
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
  iofuck;
  int t;
  cin >> t;
  string in;
  while (t--) {
    cin >> in;
    if (in.back() == 'a') {
      in.append("s");
    } else if (in.back() == 'i' || in.back() == 'y') {
      in.pop_back();
      in.append("ios");
    } else if (in.back() == 'l') {
      in.append("es");
    } else if (in.back() == 'n') {
      in.pop_back();
      in.append("anes");
    } else if (in.back() == 'o') {
      in.append("s");
    } else if (in.back() == 'r') {
      in.append("es");
    } else if (in.back() == 't') {
      in.append("as");
    } else if (in.back() == 'u') {
      in.append("s");
    } else if (in.back() == 'v') {
      in.append("es");
    } else if (in.back() == 'w') {
      in.append("as");
    } else if (in.back() == 'e') {
      bool flag = 0;
      if (in.length() >= 2) {
        if (in[in.length() - 2] == 'n') {
          flag = 1;
          in.pop_back();
          in.pop_back();
          in.append("anes");
        }
      }
      if (!flag) {
        in.append("us");
      }
    } else {
      in.append("us");
    }
    cout << in << endl;
  }
  return 0;
}