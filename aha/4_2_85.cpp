/*************************************************************************
    > File Name: 4_2_85.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Feb 28 21:37:05 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, m, p, q, minn = 999999;
int a[51][51], book[51][51];
void dfs(int x, int y, int step){
    int next[4][2] = {
        {0, 1}, 
        {1, 0}, 
        {0, -1}, 
        {-1, 0} 
    };
    int tx, ty, k;
    if(x == p && y == q){
        if(step < minn){
            minn = step;
        }
        return ;
    }

    for(k = 0; k <= 3; k++){
        tx = x + next[k][0];
        ty = y + next[k][1];

        if(tx < 1 || tx > n || ty < 1 || ty > m)
            continue;
        if(a[tx][ty] == 0 && book[ty][tx] == 0){
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
    return ;
}

int main(){
    int i, j, sx, sy;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cin >> sx >> sy >> p >> q;
    book[sx][sy] = 1;
    dfs(sx, sy, 0);
    cout << minn;
    return 0;
}
