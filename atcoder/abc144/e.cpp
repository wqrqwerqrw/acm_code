/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/28
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int n, k;
/*
bool C(int mid){
    ll cos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] * f[i] > mid){
            cos += (ll)ceil((a[i] * f[i] - mid) * 1.0 / f[i]);
            if(cos > k) return 0;
        }
    }
    return cos <= k;
}
*/
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    vi a(n), f(n);
    for(auto &i : a) cin >> i;
    for(auto &i : f) cin >> i;
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    for(auto i : a) cout << i << endl;
    int lb = 0, ub = a.back() * f.front(), mid, ans;
    /*
    while(lb <= ub){
        mid = (lb + ub) >> 1;
        if(C(mid)) ub = (ans = mid) - 1;
        else lb = mid + 1;
    }
    cout << ans << endl;
    */
    return 0;
}