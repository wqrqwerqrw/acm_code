/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/12
#include <bits/stdc++.h>
#define fi first
#define se second
#define bbb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
#define int ll
const int inf = 2e18;
const int N = 1e5 + 10;
int a[N], b[N], ta, n, m, k;
int check(int tar){
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            if(tar > 0) c1 += m;
            if(tar == 0) c2 += m;
            continue;
        }
        int tp = tar / a[i];
        if(a[i] > 0){
            if(tp * a[i] != tar) {
                c1 += upper_bound(b, b + m, tp) - b;
            } else {
                int z = upper_bound(b, b + m, tp - 1) - b;
                int tt = upper_bound(b, b + m, tp) - b;
                c1 += z;
                c2 += tt - z;
            }
        }else{
            if(tp * a[i] != tar){
                c1 += m - (lower_bound(b, b + m, tp + 1) - b);
            }else{
                int tt = m - (lower_bound(b, b + m, tp) - b);
                int z = m - (lower_bound(b, b + m, tp + 1) - b);
                c1 += z;
                c2 += tt - z;
            }
        }
    }
    if(c1 + c2 >= ta) return 1;
    else return 0;
}
signed main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
    int l = -inf, r = inf, mid, tp;
    ta = n * m - k + 1;
    while(l <= r){
        mid = (l + r) >> 1;
        cerr<<bbb(l)<<bbb(mid)<<bbb(r)<<endl;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}