// Wqr_
// Time : 20/01/18
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define int long long
typedef long long ll;
using namespace std;
signed main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    double tmp = 0;
    double i;
    for(i = 0; tmp < 1e9; i += 0.5){
        tmp += i;
    }
    cout << i*2 << endl;
    return 0;
}