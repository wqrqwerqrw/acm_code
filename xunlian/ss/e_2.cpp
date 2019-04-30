/*************************************************************************
    > File Name: e_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月29日 星期一 20时19分09秒
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
}start;
int n, m, t;
bool mark ;
bool book[10][10];
char mapp[10][10];
void dfs(node in){
    if(mark == 1) return ;
    if(in.t > t) return ;
    if(in.t == t && mapp[in.x][in.y] == 'D'){
        mark = 1;
        return ;
    }
    for(int x = -1; x <= 1; x++){
        for(int y = -1; y <= 1; y++){
            if(abs(x) == abs(y)) continue;
            int tx = in.x + x;
            int ty = in.y + y;
            if(tx >= n || ty >= m || tx < 0 || ty < 0 || book[tx][ty] || mapp[tx][ty] == 'X') continue;
            node toin;
            toin.x = tx;
            toin.y = ty;
            toin.t = in.t + 1;
            book[tx][ty] = 1;
            dfs(toin);
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
            for(int j = 0; j < m; j++){
                cin >> mapp[i][j];
                if(mapp[i][j] == 'S'){
                    start.x = i;
                    start.y = j;
                    start.t = 0;
                }
            }
        }
        book[start.x][start.y] = 1;
        dfs(start);
        if(mark) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
