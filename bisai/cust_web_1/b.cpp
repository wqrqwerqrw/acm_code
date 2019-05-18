/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 14时06分09秒
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

int main(){
    char in;
    while(scanf("%c", &in) != EOF){
        if(in == '\n') break;
        printf("%d", !(in - '0'));
    }
    printf("\n");
    return 0;
}
