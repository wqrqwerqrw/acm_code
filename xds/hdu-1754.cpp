/*************************************************************************
    > File Name: hdu-1754.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月11日 星期六 10时50分27秒
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
const int MAX_N = 1 << 18;
int n , m, dat[MAX_N * 2 - 1];
void init(int n_){
    n - 1;
    while(n < n_) n *= 2;
    for(int i = 0; i < 2 * n - 1; i++) 
        dat[i] = INT_MAX;
}
void update(int k, int a){
    k += n - 1;
    dat[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}
int query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l)
}
int main(){
    while(cin >> n >> m){

    }
    return 0;
}
