#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ll;
ll n,p,q,m,SA,SB,SC, ans = 0;
ll rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    ll t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^SA;
    return SC;
}
stack<ll> s;
void gen(){
    cin>>n>>p>>q>>m>>SA>>SB>>SC;
    ll maxn = 0;
    for(ll i = 1; i <= n;i++){
        if(rng61() % (p+q) < p){
            ll tmp = rng61() % m + 1;
            cout << tmp << endl;
            if(s.empty()) maxn = tmp;
            else if(tmp > maxn) maxn = tmp;
            s.push(maxn);
        }else{
            cout << "pop" << endl;
            if(!s.empty()) s.pop();
        }
        if(!s.empty()) ans ^= i * s.top();
    }
}
int main(){
    ll T;
    ll kase = 0;
    cin>>T;
    while(T--){
        ans = 0;
        while(!s.empty()) s.pop();
        gen();
        printf("Case #%d: %d\n", ++kase, ans);
    }
}

