// Wqr_
// Time : 20/01/19
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
signed main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, s, k;
        cin >> n >> s >> k;
        s--;
        int up = s;
        int down = s;
        vector<int> a(k);
        int flag = 0;
        for(auto &k : a){
            cin >> k;
            if(k == s) flag = 1;
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        a.push_back(s);
        sort(a.begin(), a.end());
        auto it1 = lower_bound(a.begin(), a.end(), s) - a.begin();
        auto it2 = it1 - 1;
        int ans1 = 0;
        int ans2 = 0;
        while (it1 < 1) cout << 1 << endl;
    }
    return 0;
}