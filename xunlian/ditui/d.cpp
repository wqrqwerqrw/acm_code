/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月06日 星期一 20时43分15秒
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
int ina[10100];
int inb[10100];
int n;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++){
            scanf("%d", ina + i);
            inb[i] = ina[i];
        }
        sort(ina, ina + n);
        //降
        sort(inb, inb + n, cmp);
        int a, b;
        a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(i) printf(" ");
            //小
            if(i % 2){
                printf("%d", ina[a++]);
            }else{
                printf("%d", inb[b++]);
            }
        }
        cout << endl;
    }
    return 0;
}
