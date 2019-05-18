/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 13时51分19秒
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
int main(){
    char in[1000100];
    while(scanf("%s", in) != EOF){
        int a = 0, b = 0;
        for(int i = 0; i < strlen(in); i++){
            if(in[i] == '0') a++;
            if(in[i] == '1') b++;
        }
        cout << b << " " << a << endl;
    }
    return 0;
}
