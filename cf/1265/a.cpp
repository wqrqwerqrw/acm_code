/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/05
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
  int t;
  cin >> t;
  string in;
  vector<char> ch = {'a', 'b', 'c'};
  map<char, int> mapp;
  mapp['a'] = 0;
  mapp['b'] = 1;
  mapp['c'] = 2;
  while (t--) {
    cin >> in;
    int len = in.length();
    if (len == 1) {
      if (in[0] == '?') {
        cout << 'a' << endl;
      } else {
        cout << in << endl;
      }
      continue;
    }
    bool flag = 0;
    for (int i = 0; i < len - 1; i++) {
      if (in[i] == in[i + 1] && isalpha(in[i])) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << -1 << endl;
      continue;
    }
    /////////////
    if (in[0] == '?') {
      for (int i = 0; i < 3; i++) {
        if (ch[i] != in[1]) {
          in[0] = ch[i];
          break;
        }
      }
    }
    for (int i = 1; i < len - 1; i++) {
      if (in[i] == '?') {
        if (in[i + 1] == '?') {
          for (int j = 0; j < 3; j++) {
            if (ch[j] != in[i - 1]) {
              in[i] = ch[j];
              break;
            }
          }
        } else {
          for (int j = 0; j < 3; j++) {
            if (ch[j] != in[i - 1] && ch[j] != in[i + 1]) {
              in[i] = ch[j];
              break;
            }
          }
        }
      }
    }
    if (in[len - 1] == '?') {
      for (int i = 0; i < 3; i++) {
        if (ch[i] != in[len - 2]) {
          // cout << "--" << in[len-1] << ch[i] << endl;
          in[len - 1] = ch[i];
          break;
        }
      }
    }
    cout << in << endl;
  }
  return 0;
}