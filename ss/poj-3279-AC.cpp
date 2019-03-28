/*************************************************************************
    > File Name: 3279.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Mar 11 17:54:21 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int map[16][16];
int remap[16][16];
int movee[16][16];
int m, n;
int ans = 1<<30;
void turn(int a, int b){
    if(remap[a][b] == 0) remap[a][b] = 1;
    else remap[a][b] = 0;
}
void tran(int a, int b){
    turn(a, b);
    if(a + 1 < m)
        turn(a + 1, b);
    if(b + 1 < n)
        turn(a, b + 1);
    if(a - 1 >= 0)
        turn(a - 1, b);
    if(b - 1 >= 0)
        turn(a, b - 1);
    movee[a][b] = 1;
}
bool click(){
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n ;j++){
            if(remap[i - 1][j] == 1)
                tran(i, j);
        }
    }
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(remap[m - 1][i] != 0){
            flag = false;
            break;
        }
    }
    return flag;
}
void solve(){
    bool ifimposs = true;
    for(int i = 0; i < (1<<n); i++){
        memset(movee, 0, sizeof(movee));
        memcpy(remap, map, sizeof(map));
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                tran(0, j);
            }
        }
        bool flag = click();
        if(flag){
            ifimposs = false;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(j) cout << " ";
                    cout<< movee[i][j];
                }
                cout << endl;
            }
            return ;
        }
    }
    if(ifimposs) cout << "IMPOSSIBLE" << endl;
}
int main(){
    while(cin >> m >> n){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        solve();
    }
    return 0;
}
