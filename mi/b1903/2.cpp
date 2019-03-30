/*************************************************************************
    > File Name: 2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月29日 星期五 19时11分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int map[110][110];
bool book[110][110];
struct point{
    int x, y;
}start;
int n, m;
int all;
void bfs(){
    int time = 0;
    int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numa = 0;
    memset(book, 0, sizeof(book));
    queue<point> q;
    q.push(start);
    map[start.x][start.y] = 1;
    while(!q.empty()){
        point first = q.front();
        q.pop();
        point tmp;
        bool flag = false;
        for(int i = 0; i < 4; i++){
            int ti = first.x + move[i][0];
            int tj = first.y + move[i][1];
            if(ti >= n || ti < 0 || tj >= m || tj < 0 || map[ti][tj] == -1) continue;
            if(book[ti][tj]) continue;
            book[ti][tj] = 1;
            time++;
            if(map[ti][tj] > 0) numa++;
            if(numa == all){
                flag = true;
                cout << time << endl;
                break;
            }
            for(int j = 0; j < 1 + map[ti][tj]; j++){
                tmp.x = ti;
                tmp.y = tj;
                q.push(tmp);
            }
        }
        if(flag) break;
    }
}
int main(){
    int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int num;
    cin >> num;
    while(num--){
        all = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                map[i][j] = -1;
            }
        }
        char in;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> in;
                if(in == '.'){
                    map[i][j] = 0;
                }else if(in == '#'){
                    map[i][j] = -1;
                }else if(in == 'S'){
                    start.x = i;
                    start.y = j;
                    map[i][j] = 0;
                }else{
                    map[i][j] = in - '0';
                    all++;
                }
            }
        }
        cout << "--------------" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << all;
        /*
        bool flagall = true;
        for(int i = 0; i < n; i++){
            bool flag1 = false;
            for(int j = 0; j < m; j++){
                bool flag = false;
                if(map[i][j] > 0){
                    for(int k = 0; k < 4; k++){
                        int ti = i + move[k][0];
                        int tj = j + move[k][1];
                        if(ti >= n || ti < 0 || tj >= n || tj < 0){
                            continue;
                        }
                        if(map[i][j] >= 0){
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag == false){
                    flag1 = true;
                    break;
                }
            }
            if(flag1) {
                cout << -1 << endl;
                flagall = false;
                break;
            }
        }
        if(flagall){
            bfs();
        }else{
            continue;
        }
        */
        bfs();
    }
    return 0;
}
