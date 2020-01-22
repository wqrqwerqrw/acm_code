#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2100;
int a[N],s[N];
int dp[N][N];

int32_t main(){
    #ifdef Wqr_
    freopen("in.txt","r",stdin);
    #endif
    int n;cin>>n;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) dp[i][i] = a[i];
    for(int k=2;k<=n;k++)
        for(int i=1;i<=n-1;i++){
            int j=min(n,i+k-1);
            if(j==i+1)dp[i][j]=max(dp[i][j],dp[i][i]*dp[j][j]);
            else dp[i][j]=max(dp[i][j],max(dp[i][j-1]+a[j]*(s[j-1]-s[i-1]),dp[i+1][j]+a[i]*(s[j]-s[i])));
    }
//    for(int i=1;i<=n-1;i++)
  //      for(int j=i+1;j<=n;j++)
    //        if(i==j-1)dp[i][j]=max(dp[i][j],dp[i][j-1]*dp[j][j]);
       //     else dp[i][j]=max(dp[i][j],max(dp[i][j-1]+dp[i][j-1]*dp[j][j],dp[i+1][j]+dp[i][i]*dp[i+1][j]));
    cout<<dp[1][n];
    return 0;
}