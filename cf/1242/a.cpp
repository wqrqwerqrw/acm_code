/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/06
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;
        vi v(n);
        for(auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        int maxx = -1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= v[i]; j++){
                if (n - i >= j) {
                    maxx = max(maxx, j);
                }
            }
        }
        cout << maxx << endl;
    }
    return 0;
}