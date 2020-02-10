// Wqr_
// Time : 20/01/31
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
inline int re() {
  char q = getchar();
  int x = 0;
  while (q < '0' || q > '9') q = getchar();
  while ('0' <= q && q <= '9') x = (x << 3) + (x << 1) + q - (3 << 4), q = getchar();
  return x;
}
struct Q {
  int l, r, id;
};
  signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  // std::ios::sync_with_stdio(false), cin.tie(0);
  int n, m, block;
  n = re();
  vector<int> a(n);
  for (auto& i: a) i = re();
  cin >> m;
  vector<Q> q(m);
  for (int i = 0; i < m; i++) {
    q[i].l = re(), q[i].r = re();
    // cin >> q[i].l >> q[i].r;
    q[i].id = i;
    --q[i].l;
    --q[i].r;
  }
  block = n / sqrt(m * 2 / 3);
  sort(q.begin(), q.end(), [&](const Q& a, const Q& b) {
    return (a.l / block) ^ (b.l / block) ? a.l < b.l : (((a.l / block) & 1) ? a.r < b.r : a.r > b.r);
  });
  vector<int> cnt(1000000 + 10);
  int ans = 1;
  auto add = [&](int x) {
    if (!cnt[a[x]]) ans++;
    cnt[a[x]]++;
  };
  auto del = [&](int x) {
    cnt[a[x]]--;
    if (!cnt[a[x]]) ans--;
  };
  vector<int> anss(m);
  int l = 0, r = 0;
  cnt[a[0]]++;
  for (int i = 0; i < m; i++) {
    int ql = q[i].l, qr = q[i].r;
    while (l < ql) del(l++);
    while (l > ql) add(--l);
    while (r < qr) add(++r);
    while (r > qr) del(r--);
    anss[q[i].id] = ans;
  }
  for (auto i: anss) cout << i << endl;
  return 0;
}