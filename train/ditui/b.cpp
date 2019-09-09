/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月06日 星期一 19时05分49秒
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
int num[1010];
int main(){
    string in;
    while(cin >> in){
        int t = 0;
        for(int i = 0; i < in.length(); i++){
            int tmp = 0;
            if(in[i] != '5'){
                int j;
                for(j = i; j < in.length(); j++){
                    if(in[j] == '5') break;
                    tmp = tmp * 10 + int(in[j] - '0');
                }
                i = j;
                num[t] = tmp;
                t++;
            }
        }
        sort(num, num + t);
        for(int i = 0; i < t; i++){
            if(i) printf(" ");
            printf("%d", num[i]);
        }
        printf("\n");
    }
    return 0;
}
