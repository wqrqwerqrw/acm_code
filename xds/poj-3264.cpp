/*************************************************************************
    > File Name: poj-3264.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月30日 星期四 12时58分28秒
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
const int nmax = 50000 + 5;
int n, q;
int minv[nmax << 2], maxv[nmax << 2];
void pushup(int rt){
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
    minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
}
void build(int l, int r, int rt){
    if(l == r){
        scanf("%d", minv + rt);
        //cout << minv[rt] << endl;
        maxv[rt] = minv[rt];
        return ;
    }
    int M = (l + r) >> 1;
    build(l, M, rt << 1);
    build(M + 1, r, rt << 1 | 1);
    pushup(rt);
}
int Querymax(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
        return maxv[rt];
    }
    int M = (l + r) >> 1;
    int ret = 0;
    if(L <= M) ret = max(ret, Querymax(L, R, l, M, rt << 1));
    if(R > M) ret = max(ret, Querymax(L, R, M + 1, r, rt << 1 | 1));
    return ret;
}
int Querymin(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
        return minv[rt];
    }
    int M = (l + r) >> 1;
    int ret = 1 << 30;
    if(L <= M) ret = min(ret, Querymin(L, R, l, M, rt << 1));
    if(R > M) ret = min(ret, Querymin(L, R, M + 1, r, rt << 1 | 1));
    return ret;
}
int main(){
    cin >> n >> q;
    build(1, n, 1);
    int a, b;
    while(q--){
        scanf("%d %d", &a, &b);
        printf("%d\n", Querymax(a, b, 1, n, 1) - Querymin(a, b, 1, n, 1));
    }
    return 0;
}
