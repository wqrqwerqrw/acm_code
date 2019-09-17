// Author : Wqr_
// Time : 19/09/16
#include <bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct node {
    int next, to;
} eg[maxn * 2];
int n, m, r, mod;
//见题意
int e, head[maxn], w[maxn], wt[maxn];
//链式前向星数组，w[]、wt[]初始点权数组
int a[maxn << 2], laz[maxn << 2];
//线段树数组、lazy操作
int son[maxn], id[maxn], fa[maxn], cnt, dep[maxn], siz[maxn], top[maxn];
//son[]重儿子编号,id[]新编号,fa[]父亲节点,cnt dfs_clock/dfs序,dep[]深度,siz[]子树大小,top[]当前链顶端节点
int res = 0;
//查询答案
void add(int x, int y) {
    eg[e].to = y;
    eg[e].next = head[x];
    head[x] = e++;
}
void pushdown(int rt, int l){
    laz[rt << 1] += laz[rt];
    laz[rt << 1 | 1] += laz[rt];
    a[rt << 1] += laz[rt] * (l - l / 2);
    a[rt << 1 | 1] += laz[rt] * (l / 2);
    a[rt << 1] %= mod;
    a[rt << 1 | 1] %= mod;
    laz[rt] = 0;
}
void dfs1(int x, int f, int deep) {
    dep[x] = deep;
    fa[x] = f;
    siz[x] = 1;
    int maxson = -1;
    for (int i = head[x]; ~i; i = eg[i].next) {
        int y = eg[i].to;
        if (y == f) continue;
        dfs1(y, x, deep + 1);
        siz[x] += siz[y];
        if (siz[y] > maxson) {
            son[x] = y;
            maxson = siz[y];
        }
    }
}
void dfs2(int x, int topf) {
    id[x] = ++cnt;
    wt[cnt] = w[x];
    top[x] = topf;
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (int i = head[x]; ~i; i = eg[x].next) {
        int y = eg[i].to;
        if (y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    memset(head, -1, sizeof(head));
    cin >> n >> m >> r >> mod;
    for (int i = 1; i <= n; i++) {
        scanf("%d", w + i);
    }
    int in1, in2;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &in1, &in2);
        add(in1, in2);
        add(in2, in1);
    }
    int x, y, z;
    int com;
    for (int i = 0; i < m; i++) {
        scanf("%d", &com);
        if (com == 1) {
            scanf("%d %d %d", &x, &y, &z);
        } else if (com == 2) {
            scanf("%d %d", &x, &y);
        } else if (com == 3) {
            scanf("%d %d", &x, &y);
        } else if (com == 4) {
            scanf("%d", &x);
        }
    }
    return 0;
}
