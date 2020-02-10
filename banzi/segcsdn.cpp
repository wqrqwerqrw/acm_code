#include <bits/stdc++.h>
using namespace std;
struct seqTree {
#define lc (o << 1)
#define rc ((o << 1) | 1)
#define MID ((L + R) >> 1)
#define ll long long
  int n;
  vector<ll> addv;    //增加标记
  vector<ll> sumv;    //和
  vector<ll> minv;    //最小值
  vector<ll> maxv;    //最大值
  vector<ll> A;       //值
  void treeClear() {  //清空线段树
    addv.clear();
    sumv.clear();
    minv.clear();
    maxv.clear();
    A.clear();
  }

  void treeResize(int n) {  //改变线段树的大小
    addv.resize(n << 2);
    sumv.resize(n << 2);
    minv.resize(n << 2);
    maxv.resize(n << 2);
  }

  seqTree() : n(0) {  //新建线段树
    treeClear();
  }

  seqTree(int n) : n(n), A(n + 2), addv(n << 2), sumv(n << 2), minv(n << 2), maxv(n << 2) {}  //新建大小为n的线段树

  void maintain(int o, int L, int R)  //维护
  {
    if (L == R) {
      sumv[o] = minv[o] = maxv[o] = A[L];
    }
    if (R > L) {
      sumv[o] = sumv[lc] + sumv[rc];
      minv[o] = min(minv[lc], minv[rc]);
      maxv[o] = max(maxv[lc], maxv[rc]);
    }
  }

  void dfsBuild(int o, int L, int R)  //递归建树
  {
    if (L == R) {
      sumv[o] = A[L];
      minv[o] = A[L];
      maxv[o] = A[L];
    }
    if (L < R) {
      if (MID >= L) dfsBuild(lc, L, MID);
      if (MID < R) dfsBuild(rc, MID + 1, R);
      maintain(o, L, R);
    }
  }

  void build(vector<ll> X, unsigned int L, unsigned int R)  //对数列的[L,R)建树
  {
    if (X.empty()) return;
    R = min(R, (unsigned int)X.size());
    L = max(L, (unsigned int)0);
    treeClear();
    A.push_back(0);
    for (unsigned int i = L; i < R; i++) {
      A.push_back(X[i]);
    }
    n = A.size() - 1;
    treeResize(n);
    dfsBuild(1, 1, A.size() - 1);
  }

  seqTree(vector<ll> A)  //新建一棵数列为A的线段树
  {
    build(A, 0, A.size());
  }

  void updata(int o, int L, int R, int y1, int y2, ll v) {  //对【y1,y2】增加v
    if (y1 <= L && y2 >= R) {
      addv[o] += v;
      minv[o] += v;
      maxv[o] += v;
      sumv[o] += v * (R - L + 1);
    } else {
      pushDown(o, L, R);
      if (y1 <= MID) updata(lc, L, MID, y1, y2, v);
      if (y2 > MID) updata(rc, MID + 1, R, y1, y2, v);
      maintain(o, L, R);
    }
  }

  void pushDown(int o, int L, int R)  //标记下传
  {
    if (addv[o] != 0) {
      addv[lc] += addv[o];
      addv[rc] += addv[o];
      sumv[lc] += addv[o] * (MID - L + 1);
      sumv[rc] += addv[o] * (R - MID);
      minv[lc] += addv[o];
      minv[rc] += addv[o];
      maxv[lc] += addv[o];
      maxv[rc] += addv[o];
      addv[o] = 0;
    }
  }

  ll getSum(int o, int L, int R, int y1, int y2)  //对[y1,y2]求和
  {
    if (y1 <= L && y2 >= R) {
      return sumv[o];
    }
    pushDown(o, L, R);
    ll ret = 0;
    if (y1 <= MID) ret += getSum(lc, L, MID, y1, y2);
    if (y2 > MID) ret += getSum(rc, MID + 1, R, y1, y2);
    return ret;
  }

  ll getMin(int o, int L, int R, int y1, int y2)  //对[y1,y2]求最小值
  {
    if (y1 <= L && y2 >= R) {
      return minv[o];
    }
    pushDown(o, L, R);
    ll ret = 2e9;
    if (y1 <= MID) ret = min(ret, getMin(lc, L, MID, y1, y2));
    if (y2 > MID) ret = min(ret, getMin(rc, MID + 1, R, y1, y2));
    return ret;
  }

  ll getMax(int o, int L, int R, int y1, int y2)  //对[y1,y2]求最大值
  {
    if (y1 <= L && y2 >= R) {
      return maxv[o];
    }
    pushDown(o, L, R);
    ll ret = -2e9;
    if (y1 <= MID) ret = max(ret, getMax(lc, L, MID, y1, y2));
    if (y2 > MID) ret = max(ret, getMax(rc, MID + 1, R, y1, y2));
    return ret;
  }
};
signed main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false), cin.tie(0);

  return 0;
}