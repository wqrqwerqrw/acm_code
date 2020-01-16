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
using namespace std;
typedef long long ll;
#define int ll
signed main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    vector<pair<int, int>> tmp;
    tmp.push_back({99, 100});
    tmp.push_back({100000, 100000});
    // tmp.push_back({105, 105});
    vector<pair<int, int>> nv;
    int l = tmp[0].first;
    int r = tmp[0].second;
    for(int i = 1; i < tmp.size(); i++){
        while(tmp[i].first == tmp[i-1].second + 1){
            r = tmp[i].second;
            i++;
        }
        nv.push_back({l, r});
        r = tmp[i].second;
        l = tmp[i].first;
        if(i >= tmp.size()) break;
    }
    if(l == tmp.back().first && r == tmp.back().second){
        nv.push_back({l, r});
    }
    for(auto i : nv) cerr<<"["<<i.fi<<" " << i.se<<"]";
    cerr<<endl;
    int ans = 0;
    ans += nv[0].se - nv[0].fi;
    for(int i = 1; i < nv.size(); i++){
        int cha = nv[i].second - nv[i].first;
        int ji = (nv[i].first - nv[i-1].second) * (nv[i].first - nv[i-1].second);
        cerr<< ddd(nv[i-1].se) <<ddd(nv[i].first)<<ddd(nv[i].second)<<endl;
        ans += cha;
        ans += ji;
        cerr << ddd(cha)<<ddd(ji)<<ddd(ans)<<endl;
        cerr<<"------"<<endl;
    }
    cout << ans << endl;
    return 0;
}