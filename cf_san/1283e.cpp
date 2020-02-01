/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/05
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
  vector<int> x(n);
  vector<int> cnt(n, 0);
  int minans = 0, maxans = 0;
  for (auto &i: x) {
    cin >> i;
    cnt[i - 1]++;
  }
  for (int i = 0; i < n; i++) {
    if (!cnt[i]) continue;
    minans++;
    i += 2;
  }
  map<int, bool> mapp;
  vector<vector<int>> vs;
  vector<int> tmp;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0 && tmp.size()) {
      vs.push_back(tmp);
      tmp.clear();
      continue;
    }
    if (cnt[i] == 0) continue;
    tmp.push_back(i);
    mapp[i] = 1;
  }
  if (tmp.size()) vs.push_back(tmp);
  for (auto v: vs) {
    int l = *v.begin();
    int r = *v.rbegin();
    int sum = 0;
    for (auto i: v) {
      sum += cnt[i];
      maxans++;
    }
    if (sum >= v.size() + 2) {
      if (mapp[l - 1] == 0) {
        mapp[l - 1] = 1;
        maxans++;
      }
      if (mapp[r + 1] == 0) {
        mapp[r + 1] = 1;
        maxans++;
      }
      continue;
    }
    //l
    if (sum >= v.size() + 1 && !mapp[l - 1]) {
      mapp[l - 1] = 1;
      maxans++;
      continue;
    }
    //r
    if (sum >= v.size() + 1 && !mapp[r + 1]) {
      mapp[r + 1] = 1;
      maxans++;
      continue;
    }
  }
  cout << minans << " " << maxans << endl;
  return 0;
}