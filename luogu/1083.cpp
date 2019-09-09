// Author : Wqr_
// Time : 2019/9/3 19:26:01

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 1e6 + 10;
int n, m;
int jiao[namx], d[nmax], s[nmax], t[nmax];
int ss[nmax << 2];

void pushup(int rt){
    ss[rt] == min(ss[rt << 1], ss[rt << 1 | 1]);
}

void build(int l, int r, int rt){
    if(l == r) {
        cin >> ss[rt];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

void update(int L, int R, int C, int l, int r, int rt){
    if(l > R || r < L) return ;
    if(L <= l && r <= R){
        lz[rt] = C;
        return ;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    update(L, R, C, l, mid, rt << 1);
    update(L, R, C, mid + 1, mid, rt << 1);
}

int main(){
    iofuck;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }
    for(int i = 0; i < m; i++){
        cin >> d[i] >> s[i] >> t[i];
    }
    return 0;
}
