/*************************************************************************
    > File Name: hdu-1166.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月27日 星期一 15时17分32秒
 ************************************************************************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int nmax = 50010;
int sss[nmax << 2];
int a[nmax], n;
void pushup(int rt) {
    sss[rt] = sss[rt << 1] + sss[rt << 1 | 1];
}
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", sss + rt);
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt);
}
void update(int L, int C, int l, int r, int rt) {
    if (l == r) {
        sss[rt] += C;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, C, l, m, rt << 1);
    else
        update(L, C, m + 1, r, rt << 1 | 1);
    pushup(rt);
}
int Query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sss[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += Query(L, R, l, m, rt << 1);
    if (R > m) ret += Query(L, R, m + 1, r, rt << 1 | 1);
    return ret;
}
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
        build(1, n, 1);
        string in;
        while (1) {
            cin >> in;
            int a, b;
            if (in[0] == 'E') break;
            if (in[0] == 'A') {
                scanf("%d %d", &a, &b);
                update(a, b, 1, n, 1);
            } else if (in[0] == 'S') {
                scanf("%d %d", &a, &b);
                update(a, -b, 1, n, 1);
            } else if (in[0] == 'Q') {
                scanf("%d %d", &a, &b);
                printf("%d\n", Query(a, b, 1, n, 1));
            }
        }
    }
    return 0;
}
