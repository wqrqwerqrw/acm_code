/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/13
#include <bits/stdc++.h>
#define fi first
#define se second
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl "\n"
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;
#define int long long
int n;
vector<int> son[N];
int ans[N];
vector<pair<int, int>> dfs(int cur){
    vector<pair<int, int>> tmp;
    tmp.push_back({cur, cur});
    for(auto i : son[cur]){
        for(auto j : dfs(i)){
            tmp.push_back(j);
        }
    }
    sort(tmp.begin(), tmp.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.fi < b.fi;
    });
    vector<pair<int, int>> nv;
    int l = tmp[0].fi;
    int r = tmp[0].se;
    for(int i = 1; i < tmp.size(); i++){
        while(tmp[i].fi == tmp[i-1].se + 1){
            r = tmp[i].se;
            i++;
        }
        nv.push_back({l, r});
        if(i >= tmp.size()) break;
        l = tmp[i].fi;
        r = tmp[i].se;
    }
    if(l == tmp.back().fi && r == tmp.back().se){
        nv.push_back({l, r});
    }
    ans[cur] += nv[0].se - nv[0].fi;
    for(int i = 1; i < nv.size(); i++){
        ans[cur] += nv[i].se - nv[i].fi;
        ans[cur] += (nv[i].fi - nv[i-1].se) * (nv[i].fi - nv[i-1].se);
    }
    return nv;
}
int32_t main() {
#ifdef Wqr_
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    int tmp;
    for (int i = 2; i <= n; i++) {
        cin >> tmp;
        son[tmp].push_back(i);
    }
    auto v = dfs(1);
    for (int i = 1; i <= n; i++) {
        cerr<<ddd(i);
        cout << ans[i] << endl;
    }
    return 0;
}