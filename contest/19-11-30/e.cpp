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
int jie[100];
void init(){
    jie[0] = 0;
    jie[1] = 1;
    for(int i = 2; i < 100; i++){
        jie[i] = jie[i - 1] * i;
    }
}
int n, k;
int main(){
#ifdef Wqr_
    // freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int minn = upper_bound(jie, jie + 10, k) - jie - 1;
        
        cout << minn << endl;
    }
    return 0;
}