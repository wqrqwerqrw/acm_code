/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/30
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
    int n, k;
    cin >> n;
    vector<vector<pii>> v(n);
    int a, b;
    for(auto &i : v){
        cin >> a >> b;
        i.push_back({a, 1});
        i.push_back({b, 0});
    }
    stack<vector<pii>> st;
    for(auto i : v){
        if(st.empty()){
            st.push(i);
            continue;
        }
        vector<pii> cur = st.top();
        st.pop();
        vector<pii> toin;
        for(auto j : cur){
            for(auto k : i){
                int xishu;
                int cifang;
                xishu = j.first * k.first;
                cifang = j.second + k.second;
                toin.push_back({xishu, cifang});
            }
        }
        st.push(toin);
    }
    cin >> k;
    int ans = 0;
    for(auto i : st.top()){
        if(i.second == k){
            ans += i.first;
        }
    }
    cout << ans << endl;
    return 0;
}