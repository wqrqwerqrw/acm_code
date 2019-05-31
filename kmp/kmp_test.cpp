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
void kmp_pre(string in){
    int m = in.length();
    int i, j;
    j = nextt[0] = -1;
    i = 0;
    while(i < m){
        while(-1 != j && in[i] != in[j]) j = nextt[j];
        nextt[++i] = ++j;
    }
}
int kmp_count(string zhu, string mo){
    int i, j;
    int ans = 0;
    kmp_pre(mo);
    for(int k = 0; k <= mo.length(); k++){
        cout << nextt[k] << " * ";
    }
    cout << endl;
    i = j = 0;
    while(i < zhu.length()){
        while(-1 != j && zhu[i] != mo[j]) j = nextt[j];
        i++;
        j++;
        if(j >= mo.length()){
            ans++;
            j = nextt[j];
        }
    }
    return ans;
}
int main(){
    string zhu, mo;
    cin >> zhu >> mo;
    cout << kmp_count(zhu, mo) << endl;
    return 0;
}
