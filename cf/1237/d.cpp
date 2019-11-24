/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/16
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
typedef pair<int, int> pii;
const int nmax = 1e5 + 10;
int n, arr[nmax];
struct rrr{
    bool operator()(const pii& a, const pii& b){
        return a.
    }
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    int maxn = -1;
    int minn = inf;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
        minn = min(minn, arr[i]);
    }
    if(minn * 2 >= maxn){
        for(int i = 0; i < n; i++){
            cout << -1 << " ";
        }
        cout << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){

    }
    return 0;
}