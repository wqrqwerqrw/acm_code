/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/27
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
    int n, s;
    while(t--){
        cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int maxpos = 0;
        int maxnum = 0;
        int sum = 0;
        int num1 = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(a[i] > maxnum){
                maxnum = a[i];
                maxpos = i;
            }
            if(sum <= s) num1++;
            if(sum >= s) break;
        }
        sum = 0;
        int num2 = 0;
        for(int i = 0; i < n; i++){
            if(i == maxpos) continue;
            sum += a[i];
            if(sum <= s) num2++;
            if(sum >= s) break;
        }
        if(num1 > num2) cout << 0 << endl;
        else cout << maxpos + 1 << endl;
    }
    return 0;
}