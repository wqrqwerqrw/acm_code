// Author : Wqr_
// Time : 2019/9/7 15:20:37

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int nmax = 1e5 + 50;
ll dp[nmax][3][3];
int main(){
    dp[1][0][0] = 3;
    dp[1][0][1] = 3;
    dp[1][0][2] = 3;
    dp[1][1][0] = 1;
    dp[1][1][1] = 2;
    dp[1][1][2] = 3;
    dp[1][2][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 3;
    for(int i = 2; i < 100; i++){
        dp[i][0][0] = dp[i-1][0][0] / 3 + dp[i-1][1][0] + dp[i-1][2][0];
        dp[i][0][1] = dp[i-1][0][0] / 3;
        dp[i][0][2] = dp[i-1][0][0] / 3;
        dp[i][1][0] = dp[i-1][0][1] / 3 + dp[i-1][1][1] / 2 + dp[i-1][2][0];
        dp[i][1][1] = dp[i-1][0][1] / 3 + dp[i-1][1][1] / 2;
        dp[i][1][2] = dp[i-1][0][1] / 3;
        dp[i][2][0] = dp[i-1][0][2] / 3 + dp[i-1][1][2] / 3 + dp[i-1][2][2] / 3; 
        dp[i][2][1] = dp[i-1][0][2] / 3 + dp[i-1][1][2] / 3 + dp[i-1][2][2] / 3;
        dp[i][2][2] = dp[i-1][0][2] / 3 + dp[i-1][1][2] / 3 + dp[i-1][2][2] / 3;
        ll sum = 0;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                sum += dp[i][j][k];
            }
        }
        cout << i << " : " << sum << endl;
    }
    return 0;
}
