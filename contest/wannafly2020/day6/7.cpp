// Wqr_
// Time : 20/01/17
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
typedef long long ll;
using namespace std;
int n;
signed main(){
#ifdef Wqr_
    // freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;
        vector<int> f(n), p(n);
        int allfu = 1;
        for(int i = 0; i < n; i++){
            cin >> f[i];
            if(f[i] >= 0) allfu = 0;
        }
        if(allfu) {
            for(int i = 0; i < n; i++){
                if(i) cout << " ";
                cout << i + 1;
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}