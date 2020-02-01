// Wqr_
// Time : 20/01/16
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
#define int long long
const int N = 1e5 + 10;
vector<int> G[N];
int n, f[N], ans[N];
void dfs1(int in) {
  for (auto i: G[in]) {
    if (i != f[in]) {
      f[i] = in;
      dfs1(i);
    }
  }
}
void uni(set<int>& a, set<int>& b, int& numa, int& numb) {
  if (b.size() > a.size()) a.swap(b), swap(numa, numb);
  // cerr << ddd(a.size()) << ddd(b.size()) << endl;
  for (auto i: b) {
    auto it = a.lower_bound(i);
    if (it == a.end()) {
      numa += (*a.rbegin() - i) * (*a.rbegin() - i);
    } else if (it == a.begin()) {
      numa += (*a.begin() - i) * (*a.begin() - i);
    } else {
      int ta = *it, tb = *(--it);
      numa -= (ta - tb) * (ta - tb);
      numa += (ta - i) * (ta - i);
      numa += (tb - i) * (tb - i);
    }
    a.insert(i);
  }
}
set<int> dfs2(int in) {
  set<int> sett;
  int num = 0;
  sett.insert(in);
  for (auto nx: G[in]) {
    if (nx != f[in]) {
      auto setb = dfs2(nx);
      int numb = ans[nx];
      uni(sett, setb, num, numb);
    }
  }
  ans[in] = num;
  return sett;
}
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int in;
  for (int i = 2; i <= n; i++) {
    cin >> in;
    G[in].push_back(i);
    G[i].push_back(in);
  }
  dfs1(1);
  dfs2(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}