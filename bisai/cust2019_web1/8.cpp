/*************************************************************************
    > File Name: 8.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 16时25分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
const ll mod = 1<<31;
struct Mat{
    ll m[1010][1010];
};//结构体存矩阵
Mat a,e;//a是输入的矩阵，e是单位矩阵
ll n,p;
Mat Mul(Mat x,Mat y) //矩阵乘
{
    Mat c;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        c.m[i][j]=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
          c.m[i][j]=c.m[i][j]%mod+x.m[i][k]*y.m[k][j]%mod;
    return c;
}
Mat pow(Mat x,ll y) //矩阵快速幂
{
    Mat ans=e;
    while(y)
    {
        if(y&1)
         ans=Mul(ans,x);
        x=Mul(x,x);
        y>>=1;
    }
    return ans;
}
int main(){
    cout << mod << endl;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a.m[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        e.m[i][i] = 1;
    }
    Mat ans = pow(a, p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans.m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
