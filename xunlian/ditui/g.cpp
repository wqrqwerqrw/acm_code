/*************************************************************************
    > File Name: g.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 14时18分29秒
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
ll ans[10010];
void solve(){
    ans[0] = 1;
    ans[1] = 2;
    ans[2] = 7;
    for(int i = 3; i <= 10000; i++){
        //两个射线 * 
        ans[i] = 2 * 2 * (i - 1) + ans[i - 1] + 1;
    }
}
int main(){
    int t;
    cin >> t;
    solve();
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
