// Author : Wqr_
// Time : 2019/9/6 20:20:24

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;
/*
ll extend_gcd(ll a, ll b, ll &x, ll &y){
    if(a == 0 && b == 0) return -1;
    if(b == 0){x = 1; y = 0; return a;}
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll mod_r(ll a, ll n){
    ll x, y;
    ll d = extend_gcd(a, n, x, y);
    if(d == 1) return (x % n + n) % n;
    else return -1;
}
*/
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll poww(ll a, ll b){
    ll ans = 1;
    a %= MOD;
    while(b){
        if(b % 2) ans *= a;
        a = (a * a) % MOD;
        b /= 2;
        ans %= MOD;
    }
    return ans;
}
ll mod_r(ll a, ll b){
    ll c = 1;
    for(; b; b >>= 1){
        if(b & 1) c = c * a % MOD;
        a = a * a % MOD;
    }
    return c;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        scanf("%lld", &n);
        ll up = n;
        ll dw = poww(2, n - 1);
        ll gc = gcd(up, dw);
        up /= gc;
        dw /= gc;
        ll ans = up * mod_r(dw, MOD - 2) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
