/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/12
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, k;
    cin >> n >> k;
    string in;
    cin >> in;
    unordered_map<char, bool> mapp;
    char ch;
    for(int i = 0; i < n; i++){
        cin >> ch;
        mapp[ch] = 1;
    }
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < in.length(); i++){
        if(mapp[in[i]] == 0){
            ans += (cur * (cur + 1)) / 2;
            cur = 0;
        }else{
            cur++;
        }
    }
    ans += cur * (cur + 1) / 2;
    cout << ans << endl;
    return 0;
}