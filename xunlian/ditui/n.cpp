/*************************************************************************
    > File Name: n.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 20时56分40秒
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
ll a[22];
ll b[22];
void solve(){
    a[1] = 2;
    b[1] = 2;
    for(int i = 2; i < 21; i++){
        a[i] = 3 * a[i - 1] + 2;
    }
    for(int i = 2; i < 21; i++){
        b[i] = a[i - 1] + 2;
    }
}
int main(){
    solve();
    int t;
    cin >> t;
    while(t--){
        int in;
        cin >> in;
        cout << b[in] << endl;
    }
    return 0;
}
