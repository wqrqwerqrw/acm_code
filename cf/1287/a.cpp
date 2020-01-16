/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/05
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k;
        string s;
        cin >> k >> s;
        int ans = 0;
        int tmp = 0;
        int apos = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A'){
                apos = i;
                break;
            }
        }
        for(int i = apos; i < s.length(); i++){
            if(s[i] == 'A'){
                ans = max(ans, tmp);
                tmp = 0;
                continue;
            }
            tmp++;
        }
        ans = max(ans, tmp);
        if(ans == k){
            cout << 0 << endl;
        }
        else cout << ans << endl;
    }
    return 0;
}