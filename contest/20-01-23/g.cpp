// Wqr_
// Time : 20/01/23
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
struct Q {
  int u, v, a, b, id;
};
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  for (int _ = 1; _ <= T; _++) {
    cout << "Case #" << _ << ":" << endl;
    int n, m, op, u, v, a, b, idc = 0, ccnt = 0;
    cin >> n >> m;
    int BL = n / sqrt(m * 2 / 3 * 1.0);
    vector<vector<int>> G(n + 1);
    vector<int> A(n + 1), siz(n + 1), dep(n + 1), f(n + 1), son(n + 1);
    vector<int> st(n + 1), en(n + 1), top(n + 1), dfsxu(n + 1), bl(n + 1);
    vector<ll> Ans(m), sum(n + 1);
    vector<vector<Q>> q(3);
    for (int i = 1; i <= n; i++) cin >> A[i];
    auto B = A;
    sort(B.begin() + 1, B.end());
    auto nend = unique(B.begin() + 1, B.end());
    for (int i = 1; i <= n; i++) A[i] = lower_bound(B.begin() + 1, nend, A[i]) - B.begin();
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    function<void(int)> dfs1 = [&](int x) {
      siz[x] = 1;
      dep[x] = dep[f[x]] + 1;
      for (auto nx: G[x]) {
        if (nx == f[x]) continue;
        f[nx] = x;
        dfs1(nx);
        siz[x] += siz[nx];
        if (!son[x] || siz[son[x]] < siz[nx]) son[x] = nx;
      }
    };
    stack<int> s;
    function<void(int, int)> dfs2 = [&](int x, int tp) {
      st[x] = ++idc;
      dfsxu[idc] = x;
      top[x] = tp;
      int low = s.size();
      if (son[x]) dfs2(son[x], tp);
      if (s.size() - low >= BL) {
        ccnt++;
        while (s.size() > low) bl[s.top()] = ccnt, s.pop();
      }
      for (auto nx: G[x]) {
        if (nx == f[x] || nx == son[x]) continue;
        dfs2(nx, nx);
        if (s.size() - low >= BL) {
          ccnt++;
          while (s.size() > low) bl[s.top()] = ccnt, s.pop();
        }
      }
      en[x] = idc;
      s.push(x);
    };
    auto lca = [&](int x, int y) {
      while (top[x] != top[y]) {
        if (dep[top[x]] >= dep[top[y]])
          x = f[top[x]];
        else
          y = f[top[y]];
      }
      return dep[x] < dep[y] ? x : y;
    };
    dfs1(1);
    dfs2(1, 1);
    while (s.size()) bl[s.top()] = ccnt, s.pop();
    for (int i = 0; i < m; i++) {
      cin >> op >> u >> v >> a >> b;
      if (op == 1)
        q[op].push_back({st[u], en[u], a, b, i});
      else
        q[op].push_back({u, v, a, b, i});
    }
    sort(q[1].begin(), q[1].end(), [&](const Q& a, const Q& b) {
      if (a.u / BL == b.u / BL) return a.v < b.v;
      return a.u / BL < b.u / BL;
    });
    sort(q[2].begin(), q[2].end(), [&](const Q& a, const Q& b) {
      if (bl[a.u] == bl[b.u]) return bl[a.v] < bl[b.v];
      return bl[a.u] < bl[b.u];
    });
    vector<int> vis(n + 1), num(n + 1);
    auto update = [&](int x){
      if(!vis[x]){
        vis[x] = 1;
        sum[num[A[x]]] -= B[A[x]];
        num[A[x]]++;
        sum[num[A[x]]] += B[A[x]];
      } else {
        vis[x] = 0;
        sum[num[A[x]]] -= B[A[x]];
        num[A[x]]--;
        sum[num[A[x]]] += B[A[x]];
      }
    };
    int L = 1, R = 1;
    update(1);
    for(auto i : q[1]){
      while(R < i.v) update(dfsxu[++R]);
      while(R > i.v) update(dfsxu[R--]);
      while(L < i.u) update(dfsxu[L++]);
      while(L > i.u) update(dfsxu[--L]);
      Ans[i.id] = __gcd(sum[i.a], sum[i.b]);
    }
    fill(num.begin(), num.end(), 0);
    fill(sum.begin(), sum.end(), 0);
    fill(vis.begin(), vis.end(), 0);
    auto change = [&](int u, int v){
      while(u != v){
        if (dep[u] > dep[v])
          update(u), u = f[u];
        else
          update(v), v = f[v];
      }
    };
    int lcaa;
    for(int i = 0; i < q[2].size(); i++){
      const auto& cur = q[2][i];
      if(!i){
        change(cur.u, cur.v);
        lcaa = lca(cur.u, cur.v);
        update(lcaa);
        Ans[cur.id] = __gcd(sum[cur.a], sum[cur.b]);
        update(lcaa);
        continue;
      }
      change(cur.u, q[2][i - 1].u);
      change(cur.v, q[2][i - 1].v);
      lcaa = lca(cur.u, cur.v);
      update(lcaa);
      Ans[cur.id] = __gcd(sum[cur.a], sum[cur.b]);
      update(lcaa);
    }
    for(auto i : Ans) cout << i << endl;
  }
  return 0;
}