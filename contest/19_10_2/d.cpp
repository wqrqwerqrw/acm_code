// Author : Wqr_
// Time : 19/10/02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
int main(){
    /*
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
*/
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    map<char, int> mapp;
    string in[5];
    for(int i = 0; i < 5; i++){
        cin >> in[i];
        mapp[in[i][0]]++;
    }
    int ans = -1;
    for(auto i : mapp){
        ans = max(ans, i.second);
    }
    cout << ans << endl;
    return 0;
}