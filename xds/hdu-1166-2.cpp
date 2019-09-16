// Author : Wqr_
// Time : 19/09/16
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 5e4 + 10;
struct node {
    int l, r, m, val, ls, rs, num;
};
struct tree {
    node ns[nmax << 2];
    void pushup(int rt) {
        node &now = ns[rt];
        now.val = ns[now.ls].val + ns[now.rs].val;
    }
    void build(int l, int r, int rt) {
        node &now = ns[rt];
        now.num = rt;
        now.ls = rt * 2;
        now.rs = rt * 2 + 1;
        now.l = l;
        now.r = r;
        now.m = (l + r) / 2;
        if (now.l == now.r) {
            scanf("%d", &now.val);
            return;
        }
        build(l, now.m, now.ls);
        build(now.m + 1, r, now.rs);
        pushup(rt);
    }
    void update(int L, int C, int rt) {
        node &now = ns[rt];
        if (now.l == now.r) {
            now.val += C;
            return;
        }
        if (L <= now.m)
            update(L, C, now.ls);
        else
            update(L, C, now.rs);
        pushup(rt);
    }
    int query(int L, int R, int rt) {
        node &now = ns[rt];
        if (L <= now.l && now.r <= R) {
            return now.val;
        }
        int ret = 0;
        if (L <= now.m) ret += query(L, R, now.ls);
        if (R > now.m) ret += query(L, R, now.rs);
        return ret;
    }
};
int n;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    int kase = 0;
    while (t--) {
        printf("Case %d:\n", ++kase);
        cin >> n;
        tree tr;
        tr.build(1, n, 1);
        string in;
        while (1) {
            cin >> in;
            int a, b;
            if (in[0] == 'E') break;
            if (in[0] == 'A') {
                scanf("%d %d", &a, &b);
                tr.update(a, b, 1);
            } else if (in[0] == 'S') {
                scanf("%d %d", &a, &b);
                tr.update(a, -b, 1);
            } else if (in[0] == 'Q') {
                scanf("%d %d", &a, &b);
                printf("%d\n", tr.query(a, b, 1));
            }
        }
    }
    return 0;
}