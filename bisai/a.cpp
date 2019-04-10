/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月10日 星期三 14时30分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a, b, c;
int maxn = -1;
void dfs(int have, int ping, int type){
    if(have >= a || have >= b){
        if(type == 0){
            if(have >= a){
                dfs(have - a, ping + 1, 0);
                dfs(have - a, ping + 1, 1);
            }
        }else if(type == 1){
            if(have >= b){
                dfs(have - b + c ,ping + 1, 0);
                dfs(have - b + c ,ping + 1, 1);
            }
        }
    }else{
        if(ping > maxn) maxn = ping;
        return ;
    }
}
int main(){
    cin >> n;
    cin >> a >> b >> c;
    dfs(n, 0, 0);
    dfs(n, 0, 1);
    cout << maxn;
    return 0;
}
