// Wqr_
// Time : 20/02/05
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  std::ios::sync_with_stdio(false),cin.tie(0);
  int a, b;
  cin >> a >> b;
  auto add = [&](){
    return a + b;
  };
  cout << a + b << "\n";
  return 0;
}