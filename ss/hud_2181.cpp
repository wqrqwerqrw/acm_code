/*************************************************************************
    > File Name: hud_2181.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月14日 星期日 18时15分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int G[22][3];
int m;
int cnt;
vector<int> s;
bool book[22];
void dfs(int now){
    if(s.size() == 21){
        if(now == m){
            printf("%d:  ", ++cnt);
            for(int i = 0; i < 21; i++){
                if(i) cout << " ";
                cout << s[i];
            }
            cout << endl;
        }
        return ;
    }
    for(int i = 0; i < 3; i++){
        if(!book[G[now][i]]){
            book[G[now][i]] = 1;
            s.push_back(G[now][i]);
            dfs(G[now][i]);
            book[G[now][i]] = 0;
            s.pop_back();
        }
    }
}
int main(){
    for(int i = 1 ; i <= 20; i++){
        scanf("%d %d %d", &G[i][0], &G[i][1], &G[i][2]);
    }
    while(cin >> m){
        if(!m) break;
        memset(book, 0, sizeof(book));
        cnt = 0;
        s.push_back(m);
        book[m] = 1;
        dfs(m);
    }
    return 0;
}
