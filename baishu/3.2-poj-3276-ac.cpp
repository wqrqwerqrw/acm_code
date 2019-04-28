/*************************************************************************
    > File Name: 3.2-poj-3276.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月28日 星期日 14时40分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int cow[11000];
int f[11000];
int calc(int k){
    memset(f, 0, sizeof(f));
    int res = 0, sum = 0;
    for(int i = 0; i + k - 1 < n; i++){
        if((cow[i] + sum) % 2 != 0){
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if(i - k + 1 >= 0){
            sum -= f[i - k + 1];
        }
    }

    for(int i = n - k + 1; i < n; i++){
        if((cow[i] + sum) % 2 != 0){
            return -1;
        }
        if(i - k + 1 >= 0){
            sum -= f[i - k + 1];
        }
    }
    return res;
}
void solve(){
    int ansk = 1, ansm = n;
    for(int k = 1; k <= n; k++){
        int m = calc(k);
        if(m >= 0 && m < ansm){
            ansm = m;
            ansk = k;
        }
    }
    cout << ansk << " " << ansm << endl;
}
int main(){
    cin >> n;
    char in;
    for(int i = 0; i < n; i++){
        cin >> in;
        if(in == 'B'){
            cow[i] = 1;
        }
    }
    solve();
    return 0;
}
