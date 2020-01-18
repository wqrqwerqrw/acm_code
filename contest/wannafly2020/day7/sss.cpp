// Wqr_
// Time : 20/01/18
#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
#define ddd(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
typedef long long ll;
using namespace std;
signed main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string in;
    bool b = 0;
    while(cin >> in){
        if(b){
            cout << in << "," << endl;
        }
        b = !b;
    }
    return 0;
}