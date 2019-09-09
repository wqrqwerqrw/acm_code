/*************************************************************************
    > File Name: i.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 18时39分55秒
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
int n, m;
ll a[22] = {0, 0, 1}, b[22] = {1};
void solve(){
    for(int i = 3; i < 21; i++){
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }
    for(int i = 1; i < 21; i++){
        b[i] = i * b[i - 1];
    }
}
int main(){
    int t;
    cin >> t;
    solve();
    while(t--){
        cin >> n >> m;
        cout << b[n] / b[n - m] / b[m] * a[m] << endl;
    }
    return 0;
}
