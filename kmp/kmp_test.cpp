/*************************************************************************
    > File Name: kmp_test.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月28日 星期二 16时33分00秒
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
int nextt[1000];
void kmp_pre(char in[], int m){
    int i, j;
    nextt[0] = -1;
    j = nextt[0];
    i = 0;
    while(i < m){
        while(-1 != j && in[i] != in[j]) j = nextt[j];
        nextt[++i] = ++j;
    }
}
int main(){
    char in[500];
    scanf("%c", in);
    int m = strlen(in);
    kmp_pre(in, m);
    for(int i = 0; i < m; i++){
        cout << nextt[i] << endl;
    }
    return 0;
}
