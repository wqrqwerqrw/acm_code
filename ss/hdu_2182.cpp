/*************************************************************************
    > File Name: hdu_2182.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月14日 星期日 19时49分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int lj[30];
bool mapp[30][30];
int m;
bool book[30];
int cnt;
void dfs(int now, int len){
    if(len == 20){
        if(mapp[now][m] == 1){
            printf("%d:  ", ++cnt);
            for(int i = 0; i < len; i++){
                if(i) printf(" ");
                printf("%d", lj[i]);
            }
            printf(" %d\n", m);
        }
        return ;
    }
    for(int i = 1; i <= 20; i++){
        if(mapp[now][i] && !book[i]){
            book[i] = 1;
            lj[len] = i;
            dfs(i, len + 1);
            book[i] = 0;
        }
    }
}
int main(){
    int a, b, c;
    for(int i = 1; i <= 20; i++){
        scanf("%d %d %d", &a, &b, &c);
        mapp[i][a] = 1;
        mapp[i][b] = 1;
        mapp[i][c] = 1;
    }
    while(cin >> m){
        cnt = 0;
        memset(book, 0, sizeof(book));
        if(!m) break;
        book[m] = 1;
        lj[0] = m;
        dfs(m, 0 + 1);
    }
    return 0;
}
