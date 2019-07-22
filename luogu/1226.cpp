// Author : Wqr_
// Time : 2019年07月22日 星期一 18时04分44秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
ll qpow(ll a, ll n, ll mod){
    ll re = 1;
    while(n){
        if(n & 1) re = (re * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return re % mod;
}
int main(){
    ll b, p, k;
    cin >> b >> p >> k;
    printf("%d^%d mod %d=%d", b, p, k, qpow(b, p, k));
    return 0;
}
