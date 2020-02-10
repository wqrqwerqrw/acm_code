/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-02-09 13:37:54
# @Description: Think twice . Code once. 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long 
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int cnt = 0;
void check(int a, int b){
    while(a){
        if(a % 10 == b)cnt++;
        a /= 10;
    }
}
void dabiao(int n , int x){ // x 表示 1到9 的数字， n表示是1-n
    cnt = 0;
    // cout << "x ==== " << x << endl;
    for(int i = 1; i <= n; i++){
        check(i, x);
        if(cnt == i){
            cout << i <<",";
        }
    }
}
int32_t main()
{
    // freopen("out.txt", "w", stdout);
    dabiao(1e18,1);
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
