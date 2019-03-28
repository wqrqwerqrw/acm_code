/*************************************************************************
    > File Name: 2612.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Mar 14 17:46:23 2019
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
char map[202][202];
int paidY[202][202];
int paidM[202][202];
bool bookY[202][202];
bool bookM[202][202];
struct point{
    int x, y, deep;
}begY, begM;
int n, m;
void bfsY(){
    int move[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    memset(bookY, 0, sizeof(bookM));
    queue<point> q;
    q.push(begY);
    bool flag = true;
    while(!q.empty()){
        point get = q.front();
        q.pop();
        point tmp;
        for(int i = 0; i < 4; i++){
            tmp.x = get.x + move[i][0];
            tmp.y = get.y + move[i][1];
            if(bookY[tmp.x][tmp.y]) continue;
            if(tmp.x >= n || tmp.x < 0) continue;
            if(tmp.y >= m || tmp.y < 0) continue;
            if(map[tmp.x][tmp.y] == '#') continue;
            bookY[tmp.x][tmp.y] = 1;
            tmp.deep = get.deep + 1;
            q.push(tmp);
            if(map[tmp.x][tmp.y] == '@'){
                paidY[tmp.x][tmp.y] = tmp.deep;
            }
        }
    }
}
void bfsM(){
    int move[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    memset(bookM, 0, sizeof(bookM));
    queue<point> q;
    q.push(begM);
    bool flag = true;
    while(!q.empty()){
        point get = q.front();
        q.pop();
        point tmp;
        for(int i = 0; i < 4; i++){
            tmp.x = get.x + move[i][0];
            tmp.y = get.y + move[i][1];
            if(bookM[tmp.x][tmp.y]) continue;
            if(tmp.x >= n || tmp.x < 0) continue;
            if(tmp.y >= m || tmp.y < 0) continue;
            if(map[tmp.x][tmp.y] == '#') continue;
            bookM[tmp.x][tmp.y] = 1;
            tmp.deep = get.deep + 1;
            q.push(tmp);
            if(map[tmp.x][tmp.y] == '@'){
                paidM[tmp.x][tmp.y] = tmp.deep;
            }
        }
    }
}
void movee(){
    int mins = 99999999;
    bfsY();
    bfsM();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mins = min(mins, paidY[i][j] + paidM[i][j]);
        }
    }
    cout << mins * 11 << endl;
}
int main(){
    while(cin >> n >> m){
        for(int i = 0; i < 202; i++){
            for(int j = 0; j < 202; j++){
                paidY[i][j] = paidM[i][j] = 99999999;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> map[i][j];
                if(map[i][j] == 'Y'){
                    begY.x = i;
                    begY.y = j;
                    begY.deep = 0;
                }else if(map[i][j] == 'M'){
                    begM.x = i;
                    begM.y = j;
                    begM.deep = 0;
                }
            }
        }
        movee();
    }
    return 0;
}
