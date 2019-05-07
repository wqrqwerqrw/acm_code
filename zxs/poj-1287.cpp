/*************************************************************************
    > File Name: poj-1287.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月04日 星期六 19时46分57秒
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
#define MAX_E 50100
using namespace std;
struct edge{
    int a, b, c;
}es[MAX_E];
int n, e;
int main(){
    while(cin >> n){
        if(!n) break;
        cin >> e;
        int a, b, c;
        for(int i = 0; i < e; i++){
            scanf("%d %d %d", &a, &b, &c);
            es[i] = (edge){a, b, c};
        }
        printf("%d\n", kruskal());
    }
    reutrn 0;
}
