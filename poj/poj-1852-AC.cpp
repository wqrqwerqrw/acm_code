/*************************************************************************
    > File Name: 1852.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Mar  7 21:05:46 2019
 ************************************************************************/


//AC
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int L, n;
int x[1000001];
void solve(){
    int minn = 0;
    int maxn = 0;
    for(int  i = 0; i < n; i++){
        minn = max(minn, min(x[i], L-x[i]));
        maxn = max(maxn, max(x[i], L-x[i]));
    }
    printf("%d %d\n", minn, maxn);
}
int main(){
    int num;
    scanf("%d", &num);
    while(num--){
        scanf("%d %d", &L, &n);
        for(int i = 0; i < n; i++){
            scanf("%d", x + i);
        }
        solve();
    }
    return 0;
}
