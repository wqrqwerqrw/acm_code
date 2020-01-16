/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/07
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 1e6 + 50;
struct edge {
    int to, ne;
} e[nmax * 2];
int n, q, ecnt, head[nmax], dep[nmax], siz[nmax], son[nmax], top[nmax], f[nmax];
void add(int x, int y) {
    e[++ecnt].to = y;
    e[ecnt].ne = head[x];
    head[x] = ecnt;
}
void dfs1(int x) {
    siz[x] = 1;
    dep[x] = dep[f[x]] + 1;
    for (int i = head[x]; i; i = e[i].ne) {
        int dd = e[i].to;
        if (dd == f[x]) continue;
        f[dd] = x;
        dfs1(dd);
        siz[x] += siz[dd];
        if (!son[x] || siz[son[x]] < siz[dd])
            son[x] = dd;
    }
}
int dfn, st[nmax], en[nmax];
void dfs2(int x, int tv) {
    st[x] = ++dfn;
    top[x] = tv;
    if (son[x]) dfs2(son[x], tv);
    for (int i = head[x]; i; i = e[i].ne) {
        int dd = e[i].to;
        if (dd == f[x] || dd == son[x]) continue;
        dfs2(dd, dd);
    }
    en[x] = dfn;
}
//使用调剂 y 在 x的子树内
int lca2(int x, int y){
    int t;
    while(top[x] != top[y]) t = top[y], y = f[top[y]];
    return x == y ? t : son[x];
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] >= dep[top[y]])
            x = f[top[x]];
        else
            y = f[top[y]];
    }
    return dep[x] < dep[y] ? x : y;
}

int rt;
void init(){
    ecnt = dfn = 0;
    for(int i = 0; i <= n; i++){
        head[i] = siz[i] = son[i] = top[i] = f[i] = 0;
        e[i].to = 0;
        e[i].ne = 0;
    }
    cin >> n >> q >> rt;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs1(1);
    dfs2(1, 1);
}
int main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cout << "Case #" << kase << ":" << endl;
        init();
        int ope, x;
        while (q--) {
            cin >> ope >> x;
            if (ope == 0)
                rt = x;
            if (ope == 1) {
                //说明rt在x的子树内
                if(x == rt){
                    cout << n << endl;
                    continue;
                }
                if(lca(x, rt) != x){
                //if(st[x] > st[rt] || en[x] < en[rt]){
                    cout << siz[x] << endl;
                }else{
                    cout << n - siz[lca2(x, rt)] << endl;
                }
                /*
                if (lca(rt, x) == x) {
                    int d = func(rt, x);
                    cout << n - siz[d] << endl;
                } else{
                    cout << siz[x] << endl;
                }
                */
            }
        }
    }
    return 0;
}