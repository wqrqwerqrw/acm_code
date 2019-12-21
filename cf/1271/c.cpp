/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/12/15
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int up = 0, down = 0, left = 0, right = 0;
    int n, sx, sy;
    cin >> n >> sx >> sy;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(x > sx && y > sy){
            up++;
            right++;
        }
        if(x < sx && y > sy){
            up++;
            left++;
        }
        if(x < sx && y < sy){
            down++;
            left++;
        }
        if(x > sx && y < sy){
            down++;
            right++;
        }
        if(x == sx && y > sy)
            up++;
        if(x == sx && y < sy)
            down++;
        if(y == sy && x > sx){
            right++;
        }
        if(y == sy && x < sx){
            left++;
        }
    }
    int maxn = 0;
    maxn = max(maxn, up);
    maxn = max(maxn, down);
    maxn = max(maxn, right);
    maxn = max(maxn, left);
    /*
    cout << up << " ";
    cout << down << " ";
    cout << left << " ";
    cout << right << endl;
    */
    if(up == maxn){
        cout << up << endl;
        cout << sx << " " << sy + 1 << endl;
        return 0;
    }
    if(down == maxn){
        cout << down << endl;
        cout << sx << " " << sy - 1 << endl;
        return 0;
    }
    if(right == maxn){
        cout << right << endl;
        cout << sx + 1 << " " << sy << endl;
        return 0;
    }
    if(left == maxn){
        cout << left << endl;
        cout << sx - 1 << " " << sy << endl;
        return 0;
    }
    return 0;
}