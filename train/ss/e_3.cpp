/*************************************************************************
  > File Name: e_3.cpp
  > Author: Wqr_
  > Mail: xueduanwei@126.com 
  > Created Time: 2019年04月30日 星期二 20时04分27秒
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

int n, m, t;
char mapp[10][10];
int book[10][10];
bool mark;
int startx, starty;
int endx, endy;
void dfs(int x, int y, int time){
    if(mark) return ;
    if(time > t) return ;
    if(time == t && mapp[x][y] == 'D'){
        mark = 1;
        return ;
    }
    int tmp = t - time - abs(endx - x) - abs(endy - y);
    if(tmp < 0 || tmp & 1) return ; 
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(abs(i) == abs(j)) continue;
            int tx = x + i;
            int ty = y + j;
            if(tx >= n || ty >= m || tx < 0 || ty < 0 || book[tx][ty] || mapp[tx][ty] == 'X') continue;
            book[tx][ty] = 1;
            dfs(tx, ty, time + 1);
            book[tx][ty] = 0;
        }
    }
}
int main(){
    while(cin >> n >> m >> t){
        if(!n && !m && !t) break;
        mark = 0;
        memset(book, 0, sizeof(book));
        for(int i = 0; i < n; i++){
            scanf("%s", mapp[i]);
            for(int j = 0; j < m; j++){
                if(mapp[i][j] == 'S'){
                    startx = i;
                    starty = j;
                }else if(mapp[i][j] == 'D'){
                    endx = i;
                    endy = j;
                }
            }
        }
        book[startx][starty] = 1;
        dfs(startx, starty, 0);
        if(mark) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
