/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/17
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string a[3];
    cin >> a[0] >> a[1] >> a[2];
    for(auto str : a){
        bool flag = 0;
        for(auto i : str){
            if(flag){
                if(i != '.'){
                    cout << i << endl;
                    return 0;
                }
            }
            if(i == '='){
                flag = 1;
            }
        }
        if(flag){
            cout << "You shall pass!!!" << endl;
            return 0;
        }
    }
    return 0;
}