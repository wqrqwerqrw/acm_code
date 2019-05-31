/*************************************************************************
    > File Name: poj-3461.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月31日 星期五 11时05分50秒
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
const int nmax = 10000 + 5;
int nx[nmax];
void kmp_pre(string in){
    int i = 0, j;
    j = nx[0] = -1;
    while(i < in.length()){
        while(-1 != j && in[i] != in[j]) j = nx[j];
        nx[++i] = ++j;
    }
}
int kmp_count(string zhu, string mo){
    int i = 0, j = 0, ans = 0;
    kmp_pre(mo);
    while(i < zhu.length()){
        while(-1 != j && zhu[i] != mo[j]) j = nx[j];
        ++i;
        ++j;
        if(j >= mo.length()){
            ans++;
            j = nx[j];
        }
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        //char mo[nmax];
        //char zhu[1000000 + 5];
        string mo, zhu;
        cin >> mo >> zhu;
        //scanf("%s", mo);
        //scanf("%s", zhu);
        //printf("%d\n", kmp_count(zhu, mo));
        cout << kmp_count(zhu, mo) << endl;
    }
    return 0;
}
