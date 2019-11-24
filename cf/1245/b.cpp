/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/01
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int z(double in){
    if(in - (int)in > 0) 
    return ((int)in + 1);
    else return (int)in;
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, r, p, s;
        string in;
        cin >> n;
        cin >> r >> p >> s;
        cin >> in;
        int num = 0;
        char ans[200];
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++){
            if(in[i] == 'R'){
                if(p > 0){
                    num++;
                    p--;
                    ans[i] = 'P';
                }
            }else if(in[i] == 'P'){
                if(s > 0){
                    num++;
                    s--;
                    ans[i] = 'S';
                }
            }else if(in[i] == 'S'){
                if(r > 0){
                    num++;
                    r--;
                    ans[i] = 'R';
                }
            }
        }
        if(num < z(n * 1.0 / 2)){
            cout << "NO" << endl;
        }else{
            for(int i = 0; i < n; i++){
                if(ans[i] != 'P' && ans[i] != 'S' && ans[i] != 'R'){
                    if(p > 0){
                        ans[i] = 'P';
                        p--;
                    }else if(s > 0){
                        ans[i] = 'S';
                        s--;
                    }else if(r > 0){
                        ans[i] = 'R';
                        r--;
                    }
                }
            }
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}