/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/16
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
const int nmax = 1e5 + 10;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  map<int, bool> mark;
  stack<int> st;
  int in;
  int arr[nmax];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = n - 1; i >= 0; i--) st.push(arr[i]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (mark[st.top()]) st.pop();
    cin >> in;
    if (st.top() != in) {
      mark[in] = 1;
      ans++;
      continue;
    }
    if (st.top() == in) st.pop();
  }
  cout << ans << endl;
  return 0;
}