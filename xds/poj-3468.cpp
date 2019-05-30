/*************************************************************************
    > File Name: poj-3468.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月28日 星期二 14时04分11秒
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
ll n, q;
const ll nmax = 100005;
ll sumv[nmax << 2], addv[nmax << 2];
void pushup(ll rt){
    sumv[rt] = sumv[rt << 1] + sumv[rt << 1 | 1];
}
void build(ll l, ll r, ll rt){
    if(l == r){
        scanf("%lld", sumv + rt);
        return ;
    }
    ll m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt);
}
void pushdown(ll rt, ll ln, ll rn){
    if(addv[rt]){
        addv[rt << 1] += addv[rt];
        addv[rt << 1 | 1] += addv[rt];
        sumv[rt << 1] += addv[rt] * ln;
        sumv[rt << 1 | 1] += addv[rt] * rn;
        addv[rt] = 0;
    }
}
void update(ll L, ll R, ll C, ll l, ll r, ll rt){
    if(L <= l && r <= R){
        sumv[rt] += C * (r - l + 1); 
        addv[rt] += C;
        return ;
    }
    ll m = (l + r) >> 1;
    pushdown(rt, m - l + 1, r - m);
    if(L <= m) update(L, R, C, l, m, rt << 1);
    if(R > m) update(L, R, C, m + 1, r, rt << 1 | 1);
    pushup(rt);
}
ll Query(ll L, ll R, ll l, ll r, ll rt){
    if(L <= l && r <= R){
        return sumv[rt];
    }
    ll m = (l + r) >> 1;
    pushdown(rt, m - l + 1, r - m);
    ll ANS = 0;
    if(L <= m) ANS += Query(L, R, l, m, rt << 1);
    if(R > m) ANS += Query(L, R, m + 1, r, rt << 1 | 1);
    return ANS;
}
int main(){
    cin >> n >> q;
    build(1, n, 1);
    char in;
    ll a, b, c;
    while(q--){
        cin >> in;
        if(in == 'Q'){
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", Query(a, b, 1, n, 1));
        }else{
            scanf("%lld %lld %lld", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
    }
    return 0;
}
