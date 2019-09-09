/*************************************************************************
    > File Name: 7.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 15时10分51秒
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
typedef pair<ll, ll> P;
P a[1010];
ll n, m;
int main(){
    cin >> n >> m;
    bool flag = 0;
    ll in;
    for(int i = 0; i < n; i++){
        cin >> in;
        a[i].first = in;
        a[i].second = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(a[i].first <= m) cout << a[i].second + 1 << " ";
    }
    cout << endl;
    return 0;
}
