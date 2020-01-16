/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/27
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    int r, g, b;
    while(t--){
        cin >> r >> g >> b;
        int maxl = 0;
        maxl = max(maxl, r);
        maxl = max(maxl, g);
        maxl = max(maxl, b);
        bool flag = 0;
        if(r == maxl){
            if(g + b >= r - 1) flag = 1;
        }else if(g == maxl){
            if(r + b >= g - 1) flag = 1;
        }else if(b == maxl){
            if(r + g >= b - 1) flag = 1;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}