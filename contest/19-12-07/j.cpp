/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/07
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
  unordered_map<string, int> str2int;
  vector<string> int2str = {
      "1",
      "#1",
      "2",
      "#2",
      "3",
      "4",
      "#4",
      "5",
      "#5",
      "6",
      "#6",
      "7",
  };
  str2int["1"] = 0;
  str2int["#1"] = 1;
  str2int["2"] = 2;
  str2int["#2"] = 3;
  str2int["3"] = 4;
  str2int["4"] = 5;
  str2int["#4"] = 6;
  str2int["5"] = 7;
  str2int["#5"] = 8;
  str2int["6"] = 9;
  str2int["#6"] = 10;
  str2int["7"] = 11;
  int t;
  int n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> in(n);
    string instr;
    for (int i = 0; i < n; i++) {
      cin >> instr;
      in[i] = str2int[instr];
      // cout << instr << "-";
      // cout << in[i] << " ";
    }
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      int nxt = (in[i] + m) % 12;
      if (nxt < 0) nxt += 12;
      cout << int2str[nxt];
    }
    cout << endl;
  }
  return 0;
}