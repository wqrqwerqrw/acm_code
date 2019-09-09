/*************************************************************************
    > File Name: h.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 14时41分49秒
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
double a[30], b[30];
void solve(){
    int n;
    a[1] = 1;
    for(int i = 2; i <= 10; i++){
        a[i] = a[i - 1] * i;
    }
    b[1] = 0;
    b[2] = 1;
    //错排
    for(int i = 3; i <= 10; i++){
        b[i] = (i - 1) * (b[i - 1] + b[i - 2]);
    }
}
int main(){
    int t;
    cin >> t;
    solve();
    while(t--){
        int in;
        cin >> in;
        if(in > 10) in = 10;
        printf("%.2f%%\n", b[in] / a[in] * 100);
    }
    return 0;
}
