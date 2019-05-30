/*************************************************************************
    > File Name: hdu-1698.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月29日 星期三 15时26分56秒
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
const ll nmax = 100000 + 5;
ll sumv[nmax << 2], addv[nmax << 2];
ll n, q;
void pushup(ll rt){
    sumv[rt] = sumv[rt << 1] + sumv[rt << 1 | 1];
}
void build(ll l, ll r, ll rt){
    if(l == r){
        sumv[rt] = 1;
        return ;
    }
    ll m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt);
}
void pushdown(ll rt, ll ln, ll rn){
    if(addv[rt]){
        addv[rt << 1] = addv[rt];
        addv[rt << 1 | 1] = addv[rt];
        sumv[rt << 1] = addv[rt] * ln;
        sumv[rt << 1 | 1] = addv[rt] * rn;
        addv[rt] = 0;
    }
}
void update(ll L, ll R, ll C, ll l, ll r, ll rt){
    if(L <= l && r <= R){
        sumv[rt] = C * (r - l + 1);
        addv[rt] = C;
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
    ll ANS = 0;
    pushdown(rt, l, r);
    if(L <= m) ANS += Query(L, R, l, m, rt << 1);
    if(R > m) ANS += Query(L, R, m + 1, r, rt << 1 | 1);
    return ANS;
}
void print(){
    for(int i = 0; i < n * 4; i++){
        cout << sumv[i] << " - ";
    }
    cout << endl;
}
int main(){
    ll t;
    cin >> t;
    ll kase = 0;
    while(t--){
        cin >> n >> q;
        memset(addv, 0, sizeof(addv));
        memset(sumv, 0, sizeof(sumv));
        build(1, n, 1);
        ll a, b, c;
        for(int i = 0; i < q; i++){
            scanf("%lld %lld %lld", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
        printf("Case %lld: The total value of the hook is %lld.\n", ++kase, Query(1, n, 1, n, 1));
    }
    return 0;
}
