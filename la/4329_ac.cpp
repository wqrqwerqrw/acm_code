/*************************************************************************
    > File Name: 4329_3.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月27日 星期一 13时29分18秒
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
const int nmax = 100010;
int n;
int a[nmax];
int c[nmax];
int d[nmax];
int he[nmax];
int lowbit(int in){
    return in & (-in);
}
int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += he[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x, int num){
    while(x <= 100005){
        he[x] += num;
        x += lowbit(x);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = 0;
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        for(int i = 1; i <= n; i++){
            scanf("%d", a + i);
        }
        // 更新c
        memset(he, 0, sizeof(he));
        for(int i = 1; i <= n; i++){
            c[i] = sum(a[i]);
            add(a[i], 1);
        }
        // 更新d
        memset(he, 0, sizeof(he));
        for(int i = n; i >= 1; i--){
            d[i] = sum(a[i]);
            add(a[i], 1);
        }
        // 更新ans
        for(int i = 2; i < n; i++){
            ans += c[i] * (n - i - d[i]) + d[i] * (i - c[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
