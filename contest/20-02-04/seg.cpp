#include <bits/stdc++.h>
using namespace std;
template <class T>
struct segtree {
#define nl (nc << 1)
#define nr (nc << 1 | 1)
#define MID ((L + R) >> 1)
  struct node{
    T val, l, r, lz;
    int len(){return l - r + 1;}
    int mid(){return (l + r) >> 1;}
  };
  vector<int> A;
  int n;
  vector<node> tree;
  void pushup(int nc){
    tree[nc].val = tree[nr].val + tree[nl].val;
  }
  void pushdown(int nc){
    tree[nl].lz += tree[nc].lz;
    tree[nr].lz += tree[nc].lz;
    tree[nl].val += tree[nc].lz * tree[nl].len();
    tree[nr].val += tree[nc].lz * tree[nr].len();
    tree[nc].lz = 0;
  }
  void build(int nc, int l, int r){
    ns[nc].l = l;
    ns[nc].r = l;
    if(l == r){
      ns[nc].val = A[l];
      return ;
    }
    build(nl, l, cur.mid());
    build(nr, cur.mid() + 1, r);
    pushup(nc);
  }
  void build(const vector<T>& v){
    A = v;
    build(1, 0, A.size() - 1);
  }
};
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  ios::sync_with_stdio(false),cin.tie(0);

  return 0;
}