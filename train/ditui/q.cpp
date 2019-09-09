/*************************************************************************
    > File Name: q.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月08日 星期三 16时33分44秒
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
typedef long long ll;
int a, b, c, d;
int in[4];
int tian[4];
bool book[10100];
bool mark[4];
int out[10100];
int num = 0;
void dfs(int cur){
    if(tian[0] == 0 && cur) return ;
    if(cur == 4) {
        int ans = tian[0] * 1000 + tian[1] * 100 + tian[2] * 10 + tian[3];
        if(!book[ans]){
            book[ans] = 1;
            out[num++] = ans;
        }
        return ;
    }
    for(int i = 0; i < 4; i++){
        if(mark[i]) continue;
        tian[cur] = in[i];
        mark[i] = 1;
        dfs(cur + 1);
        mark[i] = 0;
    }
}
int main(){
    bool flag = 1;
    while(cin >> in[0] >> in[1] >> in[2] >> in[3]){
        if(!flag){
            cout << endl;
        }
        if(flag){
            flag = 0;
        }
        if(!in[0] && !in[1] && !in[2] && !in[3]) break;
        memset(book, 0, sizeof(book));
        memset(mark, 0, sizeof(mark));
        memset(out, 0, sizeof(out));
        num = 0;
        dfs(0);
        int first = out[0] / 1000;
        bool kong = 1;
        for(int i = 0; i < num; i++){
            if(out[i] / 1000 != first){
                cout << endl;
                first = out[i] / 1000;
                kong = 1;
            }
            if(!kong) cout << " ";
            if(kong) kong = 0;
            cout << out[i];
        }
        cout << endl;
    }
    return 0;
}
