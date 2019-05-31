/*************************************************************************
    > File Name: hdu-4027.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月30日 星期四 14时08分51秒
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
ll n;
const ll nmax = 100000 + 5;
ll sumv[nmax << 2];
void show(ll L, ll R, ll l, ll r, ll rt){
    if(L < 1 || R > n) return ;
    if(l == r){
        cout << sumv[rt] << " - ";
        return ;
    }
    ll M = (l + r) >> 1;
    if(l <= M) show(L, R, l, M, rt << 1);
    if(r > M) show(L, R, M + 1, r, rt << 1 | 1);
}
void pushup(ll rt){
    sumv[rt] = sumv[rt << 1] + sumv[rt << 1 | 1];
}
void build(ll l, ll r, ll rt){
    if(l == r){
        scanf("%lld", sumv + rt);
        return ;
    }
    ll M = (l + r) >> 1;
    build(l, M, rt << 1);
    build(M + 1, r, rt << 1 | 1);
    pushup(rt);
}
void update(ll L, ll l , ll r, ll rt){
    if(l == r){
        sumv[rt] = sqrt(sumv[rt]);
        //show(1, n, 1, n, 1);
        //cout << endl;
        return ;
    }
    ll M = (l + r) >> 1;
    if(L <= M) update(L, l, M, rt << 1);
    else update(L, M + 1, r, rt << 1 | 1);
    pushup(rt);
}
ll query(ll L, ll R, ll l, ll r, ll rt){
    if(L <= l && r <= R){
        return sumv[rt];
    }
    ll M = (l + r) >> 1;
    ll ret = 0;
    if(L <= M) ret += query(L, R, l, M, rt << 1);
    if(R > M) ret += query(L, R, M + 1, r, rt << 1 | 1);
    return ret;
}

void sync(ll L, ll R){
    if(L < 1 || R > n) return ;
    if(query(L, R, 1, n, 1) == R - L + 1){
        return ;
    }
    if(L == R){
        //cout << "update" << endl;
        update(L, 1, n, 1);
        return ;
    }
    ll M = (L + R) >> 1;
    sync(L, M);
    sync(M + 1, R);
}
int main(){
    ll kase = 0;
    while(scanf("%lld", &n) != EOF){
        memset(sumv, 0, sizeof(sumv));
        build(1, n, 1);
        //show(1, n, 1, n, 1);
        //cout << endl;
        ll t;
        cin >> t;
        ll o, a, b;
        printf("Case #%d:\n", ++kase);
        while(t--){
            scanf("%lld %lld %lld", &o, &a, &b);
            if(o == 0){
                sync(min(a, b), max(a, b));
            }else{
                printf("%lld\n", query(min(a, b), max(a, b), 1, n, 1));
            }
        }
        printf("\n");
    }
    return 0;
}
