/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/05
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi p(n);
        vector<pii> poss;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            poss.push_back(make_pair(p[i], i));
        }
        sort(poss.begin(), poss.end());
        int maxpos = -1;
        int minpos = 1e6;
        for(int i = 0; i < n; i++){
            maxpos = max(maxpos, poss[i].second);
            minpos = min(minpos, poss[i].second);
            if(maxpos - minpos > i) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }
    return 0;
}