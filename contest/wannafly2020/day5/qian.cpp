// Wqr_
// Time : 20/01/16
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  map<int, int> times;
  set<int> sett[3];
  for (int i = 0; i < k; i++) {
    int m;
    cin >> m;
    int num;
    for (int i = 0; i < m; i++) {
      cin >> num;
      times[num]++;
      sett[i].insert(num);
    }
  }
  int ans = 0;
  for (auto i: times) {
    if (i.se >= 3) {
      for (int j = 0; j < 3; j++) {
        sett[j].erase(i.fi);
      }
      ans++;
    }
  }
  for (int i = 0; i < k; i++) {
    set<int>& a = sett[i % k];
    set<int>& b = sett[(i + 1) % k];
    set<int>& c = sett[(i + 2) % k];
    vector<int> lab;
    vector<int> lc;
    for (auto j: a) {
      if (b.find(j) != b.end()) {
        for (auto k: c) {
          if (k != j) {
            lc.push_back(k);
            break;
          }
        }
        ans++;
        lab.push_back(j);
      }
    }
    for (auto i: lab) {
      a.erase(i);
      b.erase(i);
    }
    for (auto i: lc) {
      c.erase(i);
    }
  }
  int maxn = 0;
  maxn = max(sett[0].size(), sett[1].size());
  maxn = max(sett[1].size(), sett[2].size());
  cout << ans + maxn << endl;
  return 0;
}