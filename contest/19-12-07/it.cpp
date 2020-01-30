/************************************************
# @Author:      miniLCT
# @DateTime:    2019-12-7 12:00:00
# @Description: You build it.You run it
# @More: If lots of AC,try BF,dfs,DP
***********************************************/
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[5][5], b[5][5];

void chk(int x, int i , int j){
    if(x == 1)b[i-1][j-1]++;
    if(x == 2)b[i-1][j]++;
    if(x == 3)b[i-1][j+1]++;
    if(x == 4)b[i][j-1]++;
    if(x == 6)b[i][j+1]++;
    if(x == 7)b[i+1][j-1]++;
    if(x == 8)b[i+1][j]++;
    if(x == 9)b[i+1][j+1]++;
}
int main()
{
    int t;
    cin >> t;
    for(int kkk = 1; kkk <= t;kkk++){
        memset(a , 0 , sizeof a);
        memset(b , 0 , sizeof b);
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3;j++){
                cin >> a[i][j];
                chk(a[i][j], i ,j);
            }
        }
        int px = 1,py = 1, mx = b[1][1];
        for(int i = 1; i <= 3;i++){
            for(int j = 1; j <= 3;j++){
                if(mx < b[i][j])px = i,py = j , mx = b[i][j];
            }
        }
        cout << px << " " << py << " ";
        for(int i = 1;i <= 3;i++)
            for(int j = 1;j <= 3;j++)
                if(a[i][j] == 5)b[i][j] = 9;
        int ppx = px, ppy = py,mn = b[px][py];
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3;j++){
                if(i == px && j == py)continue;
                if( b[i][j] != 0 && b[i][j] < mn){
                    ppx = i, ppy = j,mn = b[i][j];
                }
            }
        }
        if(kkk != t)cout << ppx << " " << ppy <<endl;
        else cout << ppx << " " << ppy;
    };


}

/******************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*******************************************************/
