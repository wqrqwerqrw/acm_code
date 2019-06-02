/*************************************************************************
    > File Name: poj-2406.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月31日 星期五 19时37分16秒
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
int nx[nmax];
string in;
void kmp_pre(){
    int i, j;
    j = nx[0] = -1;
    i = 0;
    while(i < in.length()){
        while(-1 != j && in[i] != in[j]) j = nx[j];
        nx[++i] = ++j;
    }
}
int main(){
    iofuck;
    while(cin >> in){
        if(in[0] == '.' && in.length() == 1) break;
        kmp_pre();
        int l = in.length();
        if(l % (l - nx[l]) == 0){
            printf("%d\n", l / (l - nx[l]));
        }else{
            printf("1\n");
        }
    }
    return 0;
}
