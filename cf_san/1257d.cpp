/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/27
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int n, m;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vi a(n), bst(n + 1, 0);
        for(auto &i : a) {
            cin >> i;
        }
        cin >> m;
        int p, s;
        for(int i = 0; i < m; i++) {
            cin >> p >> s;
            bst[s] = max(bst[s], p);
        }
        for(int i = n - 1; i >= 0; i--){
            bst[i] = max(bst[i], bst[i + 1]);
        }
        int ans = 0;
        int pos = 0, npos;
        bool flag = false;
        while(pos < n){
            ans++;
            npos = pos;
            int curmax = -1;
            while(1){
                curmax = max(curmax, a[npos]);
                if(curmax > bst[npos - pos + 1]) break;
                npos++;
                if(npos >= n) break;
            }
            if(npos == pos) {
                flag = 1;
                break;
            }
            pos = npos;
        }
        if(flag) {
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}