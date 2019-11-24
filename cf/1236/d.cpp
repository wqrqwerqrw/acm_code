/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/17
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
int n, m, k;
set<pii> con;
bool zz(int x, int y){
    if(x == 0 || y == 0 || x == n + 1 || y == m + 1) return 1;
    return con.find(mp(x, y)) != con.end();
}
int movex[4] = {-1, 1, 0, 0};
int movey[4] = {0, 0, 1, -1};
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    cout << __gcd(9, 1) << endl;
    int a, b;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        con.insert(mp(a, b));
    }
    con.insert(mp(1, 1));
    set<pii> nopi;
    for(auto i : con){
        int curx = i.first, cury = i.second;
        int nx, ny, chx, chy;
        for(int j = 0; j < 4; j++){
            nx = curx + movex[j];
            ny = cury + movey[j];
            if(zz(nx, ny)) continue;
            int num = 0;
            for(int k = 0; k < 4; k++){
                chx = nx + movex[k];
                chy = ny + movey[k];
                if(chx == 1 && chy == 1){
                    if(nx == 1 && ny == 2) continue;
                    if(nx == 2 && ny == 1) continue;
                }
                if(zz(chx, chy)) num++;
                if(num > 2){
                    nopi.insert(mp(nx, ny));
                    if(nopi.size() > 1){
                        cout << "No" << endl;
                        return 0;
                    }
                }
                if(num == 4) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}