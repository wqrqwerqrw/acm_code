/****************************************************************
# @Author:      miniLCT
# @DateTime:    2019-11-06 23:12:21
# @Description: You build it. You run it 
# @More: Once lots of AC, try Brute-force,dynamic programming 
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int cnt;
char s[10005],t[10005];
int main()
{
    int tt;
    //string s, t;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        //getchar();
        //cin >> s >> t;
        scanf("%s%s", s, t);
        //string p="",  q="";
        cnt = 0;
        int k1 = -1,k2 = -1;
        for(int i = 0; i < n;i++){
            if(s[i] != t[i]){
                cnt++;
            
            if(k1 != -1 && k2 == -1)k2 = i;
            if(k1 == -1)k1 = i;
            }
            //if(cnt==2)break;
        }
        if(cnt == 0 || cnt == 1){cout << "No"<<endl;}
        else if(cnt > 3)cout <<"No"<<endl;
        else {
            int flag = 0;
            if((s[k1] == s[k2] && t[k1] == t[k2])){
                flag = 1;
            }
            if(flag)cout <<"Yes" <<endl;
            else cout << "No" <<endl;
        }
    }
 
}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
***************************************************************************/