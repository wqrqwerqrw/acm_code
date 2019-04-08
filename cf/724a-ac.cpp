/*************************************************************************
    > File Name: 724a-ac.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月08日 星期一 18时38分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int qpow(int x, int n, int m){
    int res = 1;
    while(n > 0){
        if(n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    int a = 8;
    if(n == 0){
        cout << 1;
        return 0;
    }
    cout << qpow(8, n, 10);
    return 0;
}
