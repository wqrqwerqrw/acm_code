/*************************************************************************
    > File Name: l.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 20时05分21秒
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
ll ans[22];
void solve(){
    ans[1] = 3;
    ans[2] = 7;
    for(int i = 3; i < 21; i++){
        ans[i] = 2 * ans[i - 1] + ans[i - 2];
    }
}
int main(){
    int t;
    cin >> t;
    solve();
    while(t--){
        int in;
        cin >> in;
        cout << ans[in] << endl;
    }
    return 0;
}
