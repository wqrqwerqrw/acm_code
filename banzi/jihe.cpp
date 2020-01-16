// Wqr_
// Time : 20/01/15
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
const db eps = 1e-8;
const db pi = acos(-1);
int sign(db k){
    if(k > eps) return 1;
    if(k < -eps) return -1;
    return 0;
}
int cmp(db k1, db k2){return sign(k1 - k2);}
signed main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    return 0;
}