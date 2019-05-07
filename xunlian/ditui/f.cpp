/*************************************************************************
    > File Name: f.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 13时34分07秒
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
ll l, n, m;
ll st[501000];
bool c(ll mid){
    ll now = 0, k = m;
    if(mid < st[0]) return 0;
    for(int i = 1; i < n + 1; i++){
        if(mid < st[i] - now && mid >= st[i - 1] - now){
            k--;
            now = st[i - 1];
        }
        if(k <= 0) return 0;
        if(mid < st[i] - now) return 0;
    }
    return 1;
}
int main(){
    while(cin >> l >> n >> m){
        for(int i = 0; i < n; i++){
            scanf("%d", st + i);
        }
        st[n] = l;
        sort(st, st + n + 1);
        ll lb, ub;
        lb = 0, ub = 1000000000;
        ll mid;
        ll ans;
        while(lb <= ub){
            mid = (lb + ub) >> 1;
            if(c(mid))  ans = mid, ub = mid - 1;
            else lb = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
