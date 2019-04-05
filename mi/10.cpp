/*************************************************************************
    > File Name: 10.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月02日 星期二 21时31分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int step[99999];
int main(){
    step[1] = 1;
    step[2] = 2;
    for(int i = 3; i < 99999; i++){
        step[i] = step[i - 2] + step[i - 1];
    }
    int in;
    while(scanf("%d", &in) != EOF){
        printf("%d\n", step[in]);
    }
    return 0;
}
