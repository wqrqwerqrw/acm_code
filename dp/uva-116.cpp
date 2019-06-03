/*************************************************************************
    > File Name: uva-116.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 15时46分49秒
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
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int nmax = 100 + 5;
int n, m;
int mapp[nmax][nmax];
int dp[nmax][nmax];
int nextt[nmax][nmax];
int main(){
    iofuck;
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mapp[i][j];
            }
        }
        int ans = INF, first = 0;
        for(int j = m - 1; j >= 0; j--){
            for(int i = 0; i < n; i++){
                if(j == m - 1) dp[i][j] = mapp[i][j];
                else{
                    int rows[3] = {i, i - 1, i + 1};
                    if(i == 0) rows[1] = n - 1;
                    if(i == n - 1) rows[2] = 0;
                    sort(rows, rows + 3);
                    dp[i][j] = INF;
                    for(int k = 0; k < 3; k++){
                        int v = dp[rows[k]][j + 1] + mapp[i][j];
                        if(v < dp[i][j]){
                            dp[i][j] = v;
                            nextt[i][j] = rows[k];
                        }
                    }
                }
                if(j == 0 && dp[i][j] < ans){
                    ans = dp[i][j];
                    first = i;
                }
            }
        }
        cout << first + 1;
        for(int i = nextt[first][0], j = 1; j < m; i = nextt[i][j], j++){
            cout << " " << i + 1;
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}
