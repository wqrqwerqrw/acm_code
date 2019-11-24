/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/11/24
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
const int nmax = 2000 + 10;
bool mapp[nmax][nmax];
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int n, m, q;
bool ifbi(int x, int y){
    return (x < 0 || x == n || y < 0 || y == m);
}
bool ifman(int x, int y){
    if(ifbi(x, y)) return true;
    return mapp[x][y];
}
int silp(int x, int y){
    int ans = 0;
    int sx = 0, zy = 0;
    for(int i = 0; i < 2; i++) if(ifman(x + mx[i], y + my[i])) sx++;
    for(int i = 2; i < 4; i++) if(ifman(x + mx[i], y + my[i])) zy++;
    if(sx != 2 && zy != 2){
        mapp[x][y] = 0;
        ans++;
        for(int i = 0; i < 4; i++){
            int nx = x + mx[i];
            int ny = y + my[i];
            if(ifbi(nx, ny)) continue;
            if(mapp[nx][ny]) ans += silp(nx, ny);
        }
    }
    return ans;
}
int ope(int x, int y){
    int ans = 0;
    if(mapp[x][y]){
        mapp[x][y] = 0;
        ans++;
        for(int i = 0; i < 4; i++){
            int nx = x + mx[i];
            int ny = y + my[i];
            if(ifbi(nx, ny)) continue;
            if(mapp[nx][ny]) ans += silp(nx, ny);
        }
    }
    return ans;
}
int main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mapp[i][j] = 1;
            }
        }
        cin >> q;
        int x, y;
        for(int i = 0; i < q; i++){
            cin >> x >> y;
            cout << ope(x - 1, y - 1) << endl;
        }
    }
    return 0;
}