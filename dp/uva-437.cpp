/*************************************************************************
    > File Name: uva-437.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 17时25分45秒
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
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int nmax = 1e5;
struct block{
    int a, b, c;
}bs[nmax];
// 0->a, 1->b, 2->3
int dp[nmax][3];
int n;
int dfs(int inx, int k){
    int &ans = dp[inx][k];
    int tsa, tsb;
    if(ans > 0) return ans;
    if(k == 0){
        tsa = bs[inx].b, tsb = bs[inx].c;
        //ans += bs[inx].a;
    }else if(k == 1){
        tsa = bs[inx].a, tsb = bs[inx].c;
        //ans += bs[inx].b;
    }else{
        tsa = bs[inx].a, tsb = bs[inx].b;
        //ans += bs[inx].c;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int nxa, nxb;
            int plus;
            if(j == 0){
                nxa = bs[i].b, nxb = bs[i].c;
                plus = bs[i].a;
            }else if(j == 1){
                nxa = bs[i].a, nxb = bs[i].c;
                plus = bs[i].b;
            }else{
                nxa = bs[i].a, nxb = bs[i].b;
                plus = bs[i].c;
            }
            if(min(nxa, nxb) < min(tsa, tsb) && max(nxa, nxb) < max(tsa, tsb)){
                ans = max(ans, dfs(i, j) + plus);
            }
        }
    }
    return ans;
}
int main(){
    iofuck;
    int kase = 0;
    while(cin >> n){
        if(n == 0) break;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            cin >> bs[i].a >> bs[i].b >> bs[i].c;
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                int plus;
                if(j == 0){
                    plus = bs[i].a;
                }else if(j == 1){
                    plus = bs[i].b;
                }else{
                    plus = bs[i].c;
                }
                ans = max(ans, dfs(i, j) + plus);
            }
        }
        cout << "Case " << ++kase << ": maximum height = " << ans << endl;
    }
    return 0;
}
