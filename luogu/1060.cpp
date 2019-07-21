// Author : Wqr_
// Time : 2019年07月21日 星期日 19时53分32秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int n, m, w, c;
int dp[30030];
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> w >> c;
        for(int j = n; j >= w; j--){
            dp[j] = max(dp[j], dp[j-w] + w*c);
        }
    }
    cout << dp[n];
    return 0;
}
