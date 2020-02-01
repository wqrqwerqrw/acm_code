/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/12
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> vs;
  vector<int> tmp;
  int in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    if (tmp.empty()) {
      tmp.push_back(in);
      continue;
    }
    if (in <= tmp.back()) {
      vs.push_back(tmp);
      tmp.clear();
      tmp.push_back(in);
    } else {
      tmp.push_back(in);
    }
  }
  vs.push_back(tmp);
  int ans = 1;
  for (auto v: vs) {
    ans = max(ans, int(v.size()));
  }
  if (vs.size() >= 2) {
    for (int i = 0; i < vs.size() - 1; i++) {
      if (vs[i].size() < 2 || vs[i + 1].size() < 2) {
        continue;
      }
      if (vs[i + 1][0] > vs[i][vs[i].size() - 2]) {
        ans = max(int(vs[i + 1].size() + vs[i].size()) - 1, ans);
      }
    }
  }
  if (vs.size() >= 2) {
    for (int i = 1; i < vs.size(); i++) {
      if (vs[i].size() < 2 || vs[i - 1].size() < 2) {
        continue;
      }
      if (vs[i][1] > vs[i - 1].back()) {
        ans = max(int(vs[i].size() + vs[i - 1].size()) - 1, ans);
      }
    }
  }
  cout << ans << endl;
  return 0;
}