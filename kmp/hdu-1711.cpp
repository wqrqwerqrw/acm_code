/*************************************************************************
    > File Name: hdu-1711.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月31日 星期五 13时46分08秒
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
const int mmax = 10000 + 5;
int n, m;
int zhu[nmax], mo[mmax];
int nx[mmax];
void kmp_pre(){
    int i = 0, j;
    j = nx[0] = -1;
    while(i < m){
        while(j != -1 && mo[i] != mo[j]) j = nx[j];
        nx[++i] = ++j;
    }
}
void kmp(){
    kmp_pre();
    int i = 0, j  = 0;
    int ans = -1;
    bool flag = 0;
    while(i < n){
        while(j != -1 && zhu[i] != mo[j]) j = nx[j];
        ++i; ++j;
        if(j >= m){
            ans = i - j + 1;
            flag = 1;
            break;
        }
        if(flag) break;
    }
    printf("%d\n", ans);
    //return ans;

}
int main(){
    int t;
    cin >> t;
    while(t--){
        scanf("%d %d", &n, &m);
        memset(nx, 0, sizeof(nx));
        for(int i = 0; i < n; i++){
            scanf("%d", zhu + i);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", mo + i);
        }
        kmp();
        //printf("%d\n", kmp());
    }
    return 0;
}
