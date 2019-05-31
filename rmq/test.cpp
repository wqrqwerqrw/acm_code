/*************************************************************************
    > File Name: test.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月31日 星期五 07时58分40秒
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
typedef long long ll;
const int nmax = 1000;
int dp[nmax][nmax];
int arr[nmax];
int n;
void rmq_init(){
    for(int i = 0; i < n; i++)
        dp[i][0] = arr[i];
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++){
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int rmq(int L, int R){
    int k = 0;
    while((1 << (k + 1)) <= R - L + 1) k++;
    return min(dp[L][k], dp[R - (1 << k) + 1][k]);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }
    rmq_init();
    int a, b;
    for(;;){
        cin >> a >> b;
        cout << rmq(a, b) << endl;
    }
    return 0;
}
