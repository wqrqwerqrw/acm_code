/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/13
#include <bits/stdc++.h>
#include <streambuf>
#include <sstream>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
typedef vector<int> vi;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  vector<int> v;
  string in;
  getline(cin, in);
  stringstream fir(in);
  vector<int> ans;
  int tmp, len;
  while (fir >> tmp) {
    ans.push_back(tmp);
  }
  len = ans.size();
  while (cin >> tmp) {
    ans.push_back(tmp);
  }
  int y = ans.size() / 2;
  vi a, b;
  int i;
  for (i = 0; i < y; i++) {
    a.push_back(ans[i]);
  }
  for (; i < ans.size(); i++) {
    b.push_back(ans[i]);
  }
  for (int i = 0; i < y; i++) {
    if (i % len == 0 && i) cout << endl;
    if (i % len) cout << " ";
    cout << a[i] + b[i];
  }
  return 0;
}