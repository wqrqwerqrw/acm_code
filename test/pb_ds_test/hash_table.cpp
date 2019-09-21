// Author : Wqr_
// Time : 19/09/20
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, ll> P;
gp_hash_table<P ,int> mapp;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    mapp[P(1, 2)] = 1;
    mapp[P(3, 4)] = 1;
    cout << mapp[P(1, 2)] << mapp[P(3,4)] << endl;
    return 0;
}