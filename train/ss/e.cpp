/*************************************************************************
    > File Name: e.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月29日 星期一 19时30分17秒
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
struct node{
    int x, y, t;
    //s, x, z, y;
    bool book[4];
}start;
int n, m, t;
char mapp[10][10];
void bfs(){
    queue<node> q;
    q.push(start);
    bool flag = 0;
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        if(t == tmp.t && mapp[tmp.x][tmp.y] == 'D'){
            flag = 1;
            break;
        }
        for(int x = -1; x <= 1; x++){
            for(int y = -1; y <= 1; y++){
                if(abs(x) == abs(y)) continue;
                int tx = tmp.x + x;
                int ty = tmp.y + y;
                if(tx >= n || ty >= m || tx < 0 || ty < 0 || mapp[tx][ty] == 'X') continue;
                node toin;
                toin.x = tx;
                toin.y = ty;
                toin.t = tmp.t + 1;
                for(int i = 0; i < 4; i++){
                    toin.book[i] = 0;
                }
                if(x == -1 && y == 0) 
                toin.book[tx][ty] = 1;
                q.push(toin);
            }
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    while(cin >> n >> m >> t){
        if(!n && !m && !t) break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mapp[i][j];
                if(mapp[i][j] == 'S'){
                    start.x = i;
                    start.y = j;
                    start.t = 0;
                }
            }
        }
        for(int i = 0; i < 4; i++){
            start.book[i] = 0;
        }
        bfs();
    }
    return 0;
}
