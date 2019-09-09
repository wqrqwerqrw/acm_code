/*************************************************************************
    > File Name: j.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 19时09分05秒
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
int a, b;
ll ans[55];
void solve(){
    ans[1] = 1;
    ans[2] = 2;
    for(int i = 3; i < 52; i++){
        ans[i] = ans[i - 1] + ans[i - 2];
    }
}
int main(){
    int t;
    cin >> t;
    solve();
    while(t--){
        cin >> a >> b;
        cout << ans[b - a] << endl;
    }
    return 0;
}
