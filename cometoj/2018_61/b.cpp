/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 20时17分14秒
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
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
ll n;
ll a[20];
bool book[20];
ll pa(ll i){
    //if(book[i]) return 0;
    vector<ll> v;
    v.push_back(a[i]);
    for(ll j = 0; j < n; j++){
        if(j == i) j++;
        bool flag = 1;
        for(auto k : v){
            if(__gcd(k, a[j]) != 1) {
                flag = 0;
                break;
            }
        }
        book[j] = 1;
        if(flag) v.push_back(a[j]);
    }
    for(auto k : v){
        cout << k << "-";
    }
    cout << endl;
    cout << a[i] << "-" << v.size() << endl;
    return v.size();
}
int main(){
    iofuck;
    ll T;
    cin >> T;
    while(T--){
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            ans = max(ans, pa(i));
        }
        cout << ans << endl;
    }
    return 0;
}
