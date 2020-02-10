#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define mid ((l + r) >> 1)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define pb push_back
using namespace std;
const int maxn = 8e4 + 50;
const int inf = 0x3f3f3f3f;
int p, u;
int n, m;
int a[maxn];
int lz[maxn];
int L[maxn], R[maxn];
vector<int> v[10050];
int get_id(int pos) {
  return pos / p;
}
void update(int l, int r, int x) {
  int id = get_id(l);
  if (L[id] < l) {  //第一块暴力拆解
    v[id].clear();
    for (int i = L[id]; i <= R[id]; ++i) {
      a[i] = min(a[i], lz[id]);
      if (i >= l && i <= r) {
        a[i] = min(a[i], x);
      }
      v[id].pb(a[i]);
    }
    sort(v[id].begin(), v[id].end());
    id++;
  }
  if (id >= u) return;
  while (R[id] <= r && id < u) {  //中间的完整块
    lz[id] = min(lz[id], x);
    id++;
  }
  if (id >= u || L[id] > r) return;
  v[id].clear();
  for (int i = L[id]; i <= R[id]; ++i) {
    a[i] = min(a[i], lz[id]);
    if (i >= l && i <= r) {
      a[i] = min(a[i], x);
    }
    v[id].pb(a[i]);
  }
  sort(v[id].begin(), v[id].end());
  return;
}
int check(int lim, int l, int r) {
  int id = get_id(l);
  int res = 0;
  if (L[id] < l) {
    for (int i = l; i <= min(R[id], r); ++i) {
      a[i] = min(a[i], lz[id]);
      if (a[i] <= lim) res++;
    }
    id++;
  }
  //cout<<"res:"<<res<<endl;
  if (id >= u) return res;
  while (R[id] <= r && id < u) {  //中间的完整块
    if (lz[id] <= lim)
      res += (R[id] - L[id] + 1);
    else
      res += upper_bound(v[id].begin(), v[id].end(), lim) - v[id].begin();
    id++;
  }
  //cout<<"res2:"<<res<<endl;
  //cout<<"id:"<<id<<endl;
  if (id >= u || L[id] > r) return res;
  // dbg();
  for (int i = L[id]; i <= r; ++i) {
    a[i] = min(a[i], lz[id]);
    if (a[i] <= lim) res++;
  }
  //cout<<"res3:"<<endl;
  return res;
}
int qry(int ll, int rr, int k) {
  int l = 1, r = 1e9;
  int ans;
  //check(2, ll-1, rr-1);
  while (l <= r) {
      // dbg(l, mid, r);
    // cout<<"mid:"<<(mid)<<" c:"<<check(mid, ll, rr)<<endl;
    // dbg(ll, rr, mid, check(mid, ll, rr));
    if (check(mid, ll, rr) >= k) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int main() {
  #ifdef Wqr_
  freopen("in.txt","r",stdin);
  #endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  p = sqrt(n);
  if (p > n) p = n;
  u = (n - 1) / p + 1;  // id < u
  for (int id = 0; id < u; ++id) {
    lz[id] = inf;
    L[id] = id * p, R[id] = id * p + p - 1;
    if (id == u - 1) R[id] = n - 1;
    for (int i = L[id]; i <= R[id]; ++i) v[id].pb(a[i]);
    sort(v[id].begin(), v[id].end());
  }
  //cout<<"p:"<<p<<" u:"<<u<<endl;

   auto ddd = [&](){
    for(int i = 0; i < n; i++){
      cout << min(a[i], lz[get_id(i)]) << "-";
    }
    cout << endl;
  };

  while (m--) {
    int op, l, r, k;
    scanf("%d%d%d%d", &op, &l, &r, &k);
    l--;
    r--;
    if (op == 1) {
      update(l, r, k);
    } else {
      printf("%d\n", qry(l, r, k));
    }
    // ddd();
  }
}
/*
3 1
1 2 3
2 1 3 2
*/
