/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/13
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(f...) " [" << #f ": " << (f) << "] " <<
using namespace std;
typedef long long ll;
template <typename T>
string printValue(const T& t) {
  cout << t << ",";  //最后一个元素
}
template <typename T, typename... Args>
string printValue(const T& t, const Args&... args) {
  cout << t << ",";
  printValue(args...);
}

int32_t main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int a, b, c, d;
  a = 0;
  b = 1;
  c = 2;
  d = 4;
  cerr << ddd(1) << endl;
  return 0;
}