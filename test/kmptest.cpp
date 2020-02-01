/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/10
#include <bits/stdc++.h>
#define first fi
#define second se
using namespace std;
typedef long long ll;
vector<int> prefix_function(string s) {
  int len = s.length();
  vector<int> pi(len, 0);
  for (int i = 1; i < len; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  auto v = prefix_function("abcabc");
  for (auto &i: v) cout << i << endl;
  return 0;
}