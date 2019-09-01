/*************************************************************************
    > File Name: 4_3_94.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Mar  1 09:08:53 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct step{
    int x;
    int y;
    int num;
};
int main(){
    queue<step> Q;
    int map[51][51];
    int book[51][51];
    int sx, sy, tox, toy;
    int tx, ty;
    step start;
    step tstep;

    int n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    cin >> sx >> sy >> tox >> toy;
    book[sx][sy] = 1;
    start.x = sx;
    start.y = sy;
    start.num = 0;
    Q.push(start);
    int next[4][2]{
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    bool flag = false;
    while(!flag){
        for(int i = 0; i < 4; i++){
            tstep.x = Q.front().x + next[i][0];
            tstep.y = Q.front().y + next[i][1];
            tstep.num = Q.front().num + 1;
            if(tstep.x < 1 || tstep.y < 1 || tstep.x > n || tstep.y > m)
                continue;
            if(map[tstep.x][tstep.y] == 0 && book[tstep.x][tstep.y] == 0){
            Q.push(tstep);    
            }
            if(tstep.x == tox && tstep.y == toy){
                flag = true;
                break;
            }
        }
        Q.pop();
    }
    cout << Q.back().num;
    return 0;
}
