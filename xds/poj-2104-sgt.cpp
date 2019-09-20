// Author : Wqr_
// Time : 19/09/19
#include <algorithm>
#include <iostream>
#include <vector>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
#define nl (nc << 1)
#define nr (nc << 1 | 1)
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 50;
int n, m, a[nmax], num[nmax];
struct sgt {
    struct node {
        int l, r;
        vector<int> dat;
        int mid() { return (l + r) / 2; }
    } ns[nmax << 2];
    void pushup(int nc) {
        node& lson = ns[nl];
        node& rson = ns[nr];
        node& cur = ns[nc];
        merge(lson.dat.begin(), lson.dat.end(), rson.dat.begin(), rson.dat.end(), cur.dat.begin());
    }
    void build(int nc, int l, int r) {
        node& cur = ns[nc];
        cur.l = l, cur.r = r;
        if (l == r) {
            cur.dat.push_back(a[l - 1]);
            return;
        }
        build(nl, l, cur.mid());
        build(nr, cur.mid() + 1, r);
        cur.dat.resize(r - l + 1);
        pushup(nc);
    }
    int query(int nc, int L, int R, int C) {
        node& cur = ns[nc];
        int ret = 0;
        if (R < cur.l || cur.r < L) return ret;
        if (L <= cur.l && cur.r <= R) {
            ret += upper_bound(cur.dat.begin(), cur.dat.end(), C) - cur.dat.begin();
            return ret;
        }
        ret += query(nl, L, R, C);
        ret += query(nr, L, R, C);
        return ret;
    }
} tr;
void solve(int l, int r, int k) {
    int lb = 0, ub = n, mid;
    while (ub - lb > 1) {
        mid = (ub + lb) / 2;
        int cot = tr.query(1, l, r, num[mid]);
        if (cot >= k)
            ub = mid;
        else
            lb = mid;
    }
    cout << num[ub] << endl;
}
int main() {
    iofuck;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        num[i] = a[i];
    }
    sort(num, num + n);
    tr.build(1, 1, n);
    int ina, inb, inc;
    for (int i = 0; i < m; i++) {
        cin >> ina >> inb >> inc;
        solve(ina, inb, inc);
    }
    return 0;
}
