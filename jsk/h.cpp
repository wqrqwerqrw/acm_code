// Author : Wqr_
// Time : 2019年08月31日 星期六 12时24分07秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 50;
ll n;
ll ans;
ll atksum;
struct P{
    ll hp, atk, ci;
    double chu;
}in[maxn];
int main(){
    iofuck;
    ll t;
    cin >> t;
    ll kase = 0;
    while(t--){
        ans = 0;
        atksum = 0;
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> in[i].hp >> in[i].atk;
            atksum += in[i].atk;
            in[i].ci = 0;
            ll hp = in[i].hp;
            ll atk = in[i].atk;
            for(ll j = 1; hp > 0; j++){
                hp -= j;
                in[i].ci++;
            }
            in[i].chu = (double)in[i].ci / atk;
        }
        sort(in, in + n, [](P a, P b){return a.chu < b.chu;});
        for(ll i = 0; i < n; i++){
            ans += atksum * in[i].ci;
            atksum -= in[i].atk;
        }
        printf("Case #%lld: %lld\n",++kase , ans);
    }
    return 0;
}
