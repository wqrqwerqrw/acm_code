/*************************************************************************
    > File Name: m.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 20时31分26秒
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
ll ans[40];
int n;
void solve(){
    ans[1] = 2;
    for(int i = 2; i < 36; i++){
        ans[i] = 3 * ans[i - 1] + 2;
    }
}
int main(){
    solve();
    while(cin >> n){
        cout << ans[n] << endl;
    }
    return 0;
}
