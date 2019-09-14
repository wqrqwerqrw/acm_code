// Author : Wqr_
// Time : 19/09/13
#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 110;
ll n, x, d[nmax], h[nmax];
struct hit{
    int d, h, cha;
}scha[nmax], sd[nmax];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    iofuck;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 0; i < n; i++){
            cin >> scha[i].d >> scha[i].h;
            sd[i] = scha[i];
        }
    }
    return 0;
}