// Author : Wqr_
// Time : 2019年07月17日 星期三 18时17分36秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
double dp[10500];
int have[10500];
double zhua[10500];
int n;
double gai;
int main(){
    iofuck;
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cin >> gai >> n;
        gai = 1 - gai;
        int all = 0;
        for(int i = 0; i < n; i++){
            cin >> have[i] >> zhua[i];
            all += have[i];
            zhua[i] = 1 - zhua[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = all; j >= have[i]; j--){
                dp[j] = max(dp[j], dp[j - have[i]] * zhua[i]);
            }
        }
        for(int i = all; i >= 0; i--){
            if(dp[i] >= gai){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
