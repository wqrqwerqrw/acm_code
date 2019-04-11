/*************************************************************************
    > File Name: ctf1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月08日 星期一 20时44分37秒
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("out.txt", "w", stdout);
    int a;
    while(scanf("TTL=%d", &a) != EOF){
        getchar();
        getchar();
        if(a == 127) printf("01");
        else if(a == 63) printf("00");
        else if(a == 191) printf("10");
        else if(a == 255) printf("11");
    }
    return 0;
}

