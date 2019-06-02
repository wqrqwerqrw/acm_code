/*************************************************************************
    > File Name: poj-1961.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月31日 星期五 18时53分17秒
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
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int nmax = 1000000 + 5;
int n;
int nx[nmax];
char in[nmax];
void kmp_pre(string in){
    int i, j;
    j = nx[0] = -1;
    i = 0;
    while(i < in.length()){
        while(-1 != j && in[i] != in[j]) j = nx[j];
        nx[++i] = ++j;
    }
}
int main(){
    int kase = 0;
    while(scanf("%d", &n) && n){
        printf("Test case #%d\n", ++kase);
        scanf("%s", in);
        kmp_pre(in);
        for(int i = 1; i <= n; i++){
            if(i % (i - nx[i]) == 0 && nx[i] != 0){
                printf("%d %d\n", i, i / (i - nx[i]));
            }
        }
        printf("\n");
    }
    return 0;
}
