/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月06日 星期一 19时00分50秒
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
int in[1010];
int main(){
    int n;
    int num;
    cin >> n;
    while(n--){
        cin >> num;
        for(int i = 0; i < num; i++){
            scanf("%d", in + i);
        }
        sort(in, in + num);
        for(int i = 0; i < num; i++){
            if(i) printf(" ");
            printf("%d", in[i]);
        }
        printf("\n");
    }
    return 0;
}
