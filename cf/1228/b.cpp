// Author : Wqr_
// Time : 19/09/30
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttl(x) cout << "#" << (x) << "#" << endl;
#define ttt(x) cout << "#" << (x) << "#";
#define ttn cout << "####" << endl;
using namespace std;
typedef long long ll;
const ll nmax = 1e3 + 30;
ll h, w, r[nmax], c[nmax], mod = 1000000007;
int mapp[nmax][nmax];
ll quick_pow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b = b / 2;
    }
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> r[i];
        for(int j = 0; j < r[i]; j++){
            mapp[i][j] = 1;
        }
        mapp[i][r[i]] = 2;
    }
    bool fa = 0;
    for(int i = 0; i < w; i++){
        cin >> c[i];
        for(int j = 0; j < c[i]; j++){
            if(mapp[j][i] == 2) fa = 1;
            mapp[j][i] = 1;
        }
        if(mapp[c[i]][i] == 1) fa = 1;
        mapp[c[i]][i] = 2;
    }
    if(fa) cout << 0 << endl;
    else{
        ll num = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!mapp[i][j]) num++;
            }
        }
        cout << (quick_pow(2, num) % mod) << endl;
    }
    return 0;
}