/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/30
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
ll k;
void tr(char& in) {
  int k;
  if (isdigit(in)) {
    k = k % 10;
    in -= '0';
    in -= k;
    if (in < 0) {
      in += 10;
    }
    in %= 10;
    in += '0';
  }
  if (isalpha(in)) {
    k = k % 26;
    if (islower(in)) {
      in -= 'a';
      in -= k;
      if (in < 0) {
        in += 26;
      }
      in %= 26;
      in += 'a';
      in = toupper(in);
    } else if (isupper(in)) {
      in -= 'A';
      in -= k;
      if (in < 0) {
        in += 26;
      }
      in %= 26;
      in += 'A';
      in = tolower(in);
    }
  }
}
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string in;
  cin >> in;
  cin >> k;
  for (auto& i: in) {
    tr(i);
  }
  cout << in << endl;
  return 0;
}