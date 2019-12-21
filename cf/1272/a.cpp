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
    int q;
    cin >> q;
    int a, b, c;
    while(q--){
        cin >> a >> b >> c;
        int aa, bb, cc;
        int ans = 5e9;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                for(int k = -1; k <= 1; k++){
                    aa = a + i;
                    bb = b + j;
                    cc = c + k;
                    int tmp = abs(aa - bb) + abs(aa - cc) + abs(bb - cc);
                    ans = min(ans, tmp);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}