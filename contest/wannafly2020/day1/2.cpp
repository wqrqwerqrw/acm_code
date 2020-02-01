/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/12
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int toint(char ch) {
  if (ch >= 'a' && ch <= 'z') return ch - 'a';
  return ch - 'A' + 26;
}
char toch(int i) {
  if (i < 26) return (char)('a' + i);
  return (char)('A' + i - 26);
}
char rech(char a, char b) {
  int x = toint(a);
  int tmp = toint(b);
  int y = tmp - x;
  if (y < 0) y += 52;
  return toch(y);
}
string restr(string a, string b) {
  while (a.length() < b.length()) a += a;
  int len = b.length();
  for (int i = 0; i < len; i++) {
    b[i] = rech(a[i], b[i]);
  }
  return b;
}
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  // cout << toint('A') << endl;
  int n, m;
  cin >> n >> m;
  vector<string> vs(n);
  vector<pii> op(m);
  for (auto &i: op) {
    cin >> i.first >> i.second;
  }
  for (auto &i: vs) {
    cin >> i;
  }
  for (int i = m - 1; i >= 0; i--) {
    vs[op[i].second - 1] = restr(vs[op[i].first - 1], vs[op[i].second - 1]);
  }
  for (auto &i: vs) {
    cout << i << endl;
  }
  return 0;
}