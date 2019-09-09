/*************************************************************************
    > File Name: k.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月07日 星期二 19时18分28秒
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
ll ans[55];
void solve(){
    ans[1] = 3;
    ans[2] = 6;
    ans[3] = 6;
    for(int i = 4; i < 51; i++){
        ans[i] = ans[i - 1] + 2 * ans[i - 2];
    }
}
int main(){
    solve();
    int n;
    while(cin >> n){
        cout << ans[n] << endl;
    }
    return 0;
}
