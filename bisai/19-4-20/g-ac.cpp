/*************************************************************************
    > File Name: g.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 14时48分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int m, n;
bool map[110][110];
void dfs(int a, int b){
    map[a][b] = 0;
    for(int dx = -1; dx < 2; dx++){
        for(int dy = -1; dy < 2; dy++){
            int nx = a + dx;
            int ny = b + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny])
                dfs(nx, ny);
        }
    }
}
int main(){
    while(cin >> n >> m){
        if(!m && !n) break;
        int ans = 0;
        char in;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> in;
                if(in == '@') map[i][j] = 1;
                else continue;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
