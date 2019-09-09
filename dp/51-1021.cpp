// Author : Wqr_
// Time : 2019年06月11日 星期二 19时55分40秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
int n;
const int nmax = 100 + 5;
vector<int> zi(nmax);
int dp[nmax][nmax];
int main(){
    iofuck;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> zi[i];
        dp[i][i] = zi[i];
    }

    return 0;
}
