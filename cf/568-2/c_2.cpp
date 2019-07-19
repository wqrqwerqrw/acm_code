// Author : Wqr_
// Time : 2019年06月19日 星期三 23时16分40秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
ll n, m;
int main(){
    //iofuck;
    cin >> n >> m;
    ll past = 0;
    priority_queue<ll> q;
    ll t;
    int tmpp = 0;
    for(ll i = 0; i < n; i++){
        ll ans = 0;
        cin >> t;
        past += t;
        vector<int> v;
        if(past > m){
            past += tmpp;
            while(past > m){
                tmp -= q.top();
                tmpp = q.top();
                q.pop();
                ans++;
            }
        }
        q.push(tmpp);
        q.push(t);
        cout << ans << " ";
    }
    return 0;
}
