/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-01-16 14:28:42
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
//#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
//#define endl '\n'
//#define int long long
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const int linf = 0x3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int t , n;

int bin(int x, int n, int MOD) {
    int ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
int get_inv(int x, int p) { return bin(x, p - 2, p); }
int main()
{
    //close;
    scanf("%d", &t);
    while(t --){
        cin >> n;
        if(n == 2){
            //cout << 0 <<  endl;
            printf("0\n");
            continue;
        }
        int cnt = 0;
        vector<int > left, right, factor;
        if((n+1) % 4 == 0){
            int zcj = n+1;
            int m = sqrt(n+1+0.5);
            for(int i = 2; i <= m; i++){
                if(zcj % i == 0){
                    left.push_back(i);
                    if(i != zcj / i){
                        left.push_back(zcj / i);
                    }
                }
            }
            sort(left.begin(), left.end());
            int cnt = left.size();
            printf("%d\n",cnt);
            for(int i = 0; i < cnt;i++){
                printf("%d %d\n",left[i], left[cnt - 1 - i]);
            }
        }
        else {
            set <int >sle,sre;
            int zcj = n +1 ;
            int m = sqrt(zcj+0.5);
            int mn = linf;
            int zb;
            for(int i = 2; i <= m; i++){
                zb = get_inv(i,n);
                if(zb < mn){
                    mn = zb;
                    sre.insert(zb);
                    left.push_back(i);
                    right.push_back(zb);
                }
            }
            for(int j = m+1; j < zb;j++){
                if(sre.count(j))break;
                int zbtxdy = get_inv(j , n);
                if(zbtxdy < mn){
                    sle.insert(j);
                    sre.insert(zbtxdy);
                    left.push_back(j);
                    right.push_back(zbtxdy);
                    mn = zbtxdy;
                    zb = zbtxdy;
                }
            }
            int np = left.size();
            for(int i = 0; i < np; i++){
                left.push_back(right[i]);
            }
            sort(left.begin(), left.end());
            int ANS = left.size();
            printf("%d\n",ANS);
            for(int i = 0; i < ANS;i++){
                printf("%d %d\n",left[i], left[ANS-1-i]);
            }
        }
    }

}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/
