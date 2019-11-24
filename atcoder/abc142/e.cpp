/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/16
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define inf 0x3f3f3f3f
const int mmax = 1e3 + 10;
int a[mmax], b[mmax];
vi c[mmax];
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        int tmp;
        for(int j = 0; j < b[i]; j++){
            cin >> tmp;
            c[i].push_back(tmp);
        }
    }
    vi dp((1 << n) + 100, inf);
    dp[0] = 0;
    for(int i = 0; i < m; i++){
        int val = 0;
        for(auto j : c[i]) val |= (1 << (j-1));
        for(int j = 0; j < (1 << n); j++){
            dp[j | val] = min(dp[j | val], a[i] + dp[j]);
        }
    }
    if(dp[(1<<n)-1] == inf) dp[(1<<n)-1] = -1;
    cout << dp[(1<<n)-1] << endl;
    return 0;
}