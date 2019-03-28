/*************************************************************************
    > File Name: R_4_2_85.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Mar  1 08:10:51 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, m, tox, toy;
int mins = 9999999;
int a[51][51];
int book[51][51];
void dfs(int x, int y, int step){
    int next[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    if(x == tox && y == toy){
        if(step < mins){
            mins = step;
        }
        return;
    }

    int tx, ty;
    for(int i = 0; i < 4; i++){
        tx = x + next[i][0];
        ty = y + next[i][1];
        if(tx < 1 || ty < 1 || tx > n || ty > m){
            continue;
        }
        if(a[tx][ty] == 0 && book[tx][ty] == 0) {
        book[tx][ty] = 1;
        dfs(tx, ty, step + 1);
        book[tx][ty] = 0;
        }
    }
    return;
}

int main(){
    int sx, sy;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    cin >> sx >> sy >> tox >> toy;
    book[sx][sy] = 1;
    dfs(sx, sy, 0);
    cout << mins;
    return 0;
}
