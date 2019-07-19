// Author : Wqr_
// Time : 2019年07月17日 星期三 18时32分51秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
double q;
int n;
int dp[1000 * 30 * 100 + 5];
int main(){
    iofuck;
    while(cin >> q >> n && n){
        memset(dp, 0, sizeof(dp));
        int m;
        for(int i = 0; i < n; i++){
            cin >> m;
            bool flag = 1;
            char str[1000];
            double price_all = 0;
            double a = 0, b = 0, c = 0;
            for(int j = 0; j < m; j++){
                cin >> str;
                double price;
                sscanf(&str[2], "%lf", &price);
                if(str[0] == 'A'){
                    a += price;
                    //cout << "as;dfkjasdfj" << endl;
                }else if(str[0] == 'B'){
                    b += price;
                }else if(str[0] == 'C'){
                    c += price;
                }else{
                    flag = 0;
                }
            }
            price_all = a + b + c;
            if(a > 600 || b > 600 || c > 600 || price_all > 1000){
                flag = 0;
            }
            int price_all_int;
            if(flag)  price_all_int = price_all * 100;
            else price_all_int = 0;
            for(int j = q * 100; j >= price_all_int; j--){
                dp[j] = max(dp[j], dp[j - price_all_int] + price_all_int);
            }
        }
        printf("%.2f\n", dp[(int)(q * 100)] / 100.0);
    }
    return 0;
}
