#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>
#include <vector>
#define ZERO(x) memset((x),0,sizeof(x))
using namespace std;
//const int maxn=;
int x[1005],y[1005];
double dp[1005][1005];
double dist[1005][1005];
double inf;
int n;
int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(dp,0x43,sizeof(dp));
        inf=dp[0][0];
        for(int i=1;i<=n;++i)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<i;++j)
                dist[j][i]=dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        for(int i=n-1;i>=1;--i)
            for(int j=1;j<i;++j)
                if(i==n-1) dp[i][j]=dist[i][n]+dist[j][n]; 
                else dp[i][j]=min(dp[i+1][j]+dist[i][i+1],dp[i+1][i]+dist[i+1][j]);
        printf("%.2lf\n",dp[2][1]+dist[1][2]);
    }
    return 0;
}
