/*************************************************************************
    > File Name: 1426.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Mar 11 19:16:29 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int in;
bool dfs(unsigned long long int num,int deep){
    if(deep > 19) return 0;
    if(num % in == 0) {
        cout << num << endl;
        return 1;
    }
    if(dfs(num * 10, deep + 1)) return 1;
    if(dfs(num * 10 + 1, deep + 1)) return 1;
    return 0;
}
int main(){
    while(cin >> in){
        if(in == 0) break;
        dfs(1, 0);
    }
    return 0;
}
