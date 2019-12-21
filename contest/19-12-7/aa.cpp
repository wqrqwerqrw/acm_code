/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/07
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
    int n;
    cin >> n;
    n++;
    while(n--){
        string in;
        getline(cin, in);
        if(in[0] == 'C')
            cout << "Awww man." << endl;
        if(in[0] == 'A')
            cout << "Se no!" << endl;
        if(in[0] == 'S')
            cout << "Creeper?" << endl;
    }
    return 0;
}