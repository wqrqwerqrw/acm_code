/*************************************************************************
    > File Name: hdu-1754.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月27日 星期一 15时17分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int nmax = 200020;
int sss[nmax << 2];
int a[nmax], n, m;
void pushup(int rt){
    sss[rt] = max(sss[rt << 1], sss[rt << 1 | 1]);
}
void build(int l, int r, int rt){
    if(l == r){
        scanf("%d", sss + rt);
        return ;
    }
    int M = (l + r) >> 1;
    build(l, M, rt << 1);
    build(M + 1, r, rt << 1 | 1);
    pushup(rt);
}
void update(int L, int C, int l, int r, int rt){
    if(l == r){
        sss[rt] = C;
        return ;
    }
    int M = (l + r) >> 1;
    if(L <= M) update(L, C, l, M, rt << 1);
    else update(L, C, M + 1, r, rt << 1 | 1);
    pushup(rt);
}
int Query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
        return sss[rt];
    }
    int M = (l + r) >> 1;
    int ret = 0;
    if(L <= M) ret = max(ret, Query(L, R, l, M, rt << 1));
    if(R > M) ret = max(ret, Query(L, R, M + 1, r, rt << 1 | 1));
    return ret;
}
int main(){
    while(cin >> n >> m){
        build(1, n, 1);
        char in;
        int a, b;
        for(int i = 0; i < m; i++){
            cin >> in;
            cin >> a >> b;
            if(in == 'Q'){
                printf("%d\n", Query(a, b, 1, n, 1));
            }else{
                update(a, b, 1, n, 1);
            }
        }
    }
    return 0;
}

