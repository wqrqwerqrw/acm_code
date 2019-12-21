/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/15
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    // type1 : a, d
    // type2 : b, c, d
    int t1 = min(a, d);
    int t2 = min(b, c);
    t2 = min(t2, d);
    int ans = 0;
    for(int i = 0; i <= t1; i++){
        int tmp = i * e;
        int dtmp = d - i;
        tmp += min(t2, dtmp) * f;
        ans = max(ans, tmp);
    }

    for(int i = 0; i <= t2; i++){
        int tmp = i * f;
        int dtmp = d - i;
        tmp += min(t1, dtmp) * e;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}