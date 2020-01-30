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
const int maxn = 1000 + 10;
int n;
int l = 0, r = 0;
char tu[maxn][maxn];
char vs[4] = {'^', '>', 'v', '<'};
unordered_map<char, int> vsmap;
char ch(char in){
    if(in == '.') return '.';
    return vs[(vsmap[in] + 1) % 4];
}
void ror(){
    char tmp[maxn][maxn];
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            tmp[j][n - 1 - i] = ch(tu[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tu[i][j] = tmp[i][j];
        }
    }
}
void rol(){
    ror();
    ror();
    ror();
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    vsmap['^'] = 0;
    vsmap['>'] = 1;
    vsmap['v'] = 2;
    vsmap['<'] = 3;
    /*
    cout << vs[(vsmap['^'] + 1) % 4] << endl;
    cout << vs[(vsmap['>'] + 1) % 4] << endl;
    cout << vs[(vsmap['v'] + 1) % 4] << endl;
    cout << vs[(vsmap['<'] + 1) % 4] << endl;
    */
    cin >> n;
    string o;
    cin >> o;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tu[i][j];
        }
    }
    for(auto i : o){
        if(i == 'L') l++;
        if(i == 'R') r++;
    }
    l %= 4;
    r %= 4;
    int tmpl = l, tmpr = r;
    r = max(tmpl, tmpr) - tmpl;
    l = max(tmpl, tmpr) - tmpr;
    for(int i = 0; i < l; i++){
        rol();
    }
    for(int i = 0; i < r; i++){
        ror();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tu[i][j];
        }
        cout << endl;
    }
    return 0;
}