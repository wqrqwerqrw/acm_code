// Wqr_
// Time : 20/02/02
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
#define inf 0x3f3f3f3f
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int& i: a) cin >> i;
  int Bsiz = sqrt(n);
  int Bnum = (n - 1) / Bsiz + 1;
  vector<int> L(Bnum), R(Bnum), lz(Bnum);
  vector<vector<int>> v(Bnum);
  for (int id = 0; id < Bnum; id++) {
    lz[id] = inf;
    L[id] = id * Bsiz;
    R[id] = L[id] + Bsiz - 1;
    if (id == Bnum - 1) R[id] = n - 1;
    for (int i = L[id]; i <= R[id]; i++) v[id].push_back(a[i]);
    sort(v[id].begin(), v[id].end());
  }
  auto getid = [&](int x) { return x / Bsiz; };
  auto update = [&](int l, int r, int k) {
    int id = getid(l);
    if (L[id] < l) {
      v[id].clear();
      for (int i = L[id]; i <= R[id]; i++) {
        a[i] = min(a[i], lz[id]);
        if (l <= i && i <= r) a[i] = min(a[i], k);
        v[id].push_back(a[i]);
      }
      sort(v[id].begin(), v[id].end());
      id++;
    }
    if (id >= Bnum) return;
    while (R[id] <= r && id < Bnum) {
      lz[id] = min(lz[id], k);
      id++;
    }
    if (id >= Bnum || L[id] > r) return;
    v[id].clear();
    for (int i = L[id]; i <= R[id]; i++) {
      a[i] = min(a[i], lz[id]);
      if (i >= l && i <= r) a[i] = min(a[i], k);
      v[id].push_back(a[i]);
    }
    sort(v[id].begin(), v[id].end());
  };
  auto check = [&](int l, int r, int k) {
    int id = getid(l);
    int ret = 0;
    if (L[id] < l) {
      for (int i = l; i <= min(R[id], r); i++) {
        a[i] = min(a[i], lz[id]);
        if (a[i] <= k) ret++;
      }
      id++;
    }
    if (id >= Bnum) return ret;
    while (R[id] <= r && id < Bnum) {
      if (lz[id] <= k)
        ret += (R[id] - L[id] + 1);
      else
        ret += upper_bound(v[id].begin(), v[id].end(), k) - v[id].begin();
      id++;
    }
    if (id >= Bnum || L[id] > r) return ret;
    for (int i = L[id]; i <= r; i++) {
      a[i] = min(a[i], lz[id]);
      if (a[i] <= k) ret++;
    }
    return ret;
  };
  auto query = [&](int l, int r, int k) {
    int lb = 1, ub = 1e9, mid, ans;
    while (lb <= ub) {
      mid = (lb + ub) >> 1;
      if (check(l, r, mid) >= k) {
        ans = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }
    return ans;
  };
  auto ddd = [&]() {
    for (int i = 0; i < n; i++) {
      cout << min(a[i], lz[getid(i)]) << "-";
    }
    cout << endl;
  };
  while (m--) {
    int ope, l, r, k;
    cin >> ope >> l >> r >> k;
    l--, r--;
    if (ope == 1)
      update(l, r, k);
    else
      cout << query(l, r, k) << endl;
  }
  return 0;
}