/*************************************************************************
    > File Name: scanf_test.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月31日 星期日 20时55分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool book[1<<20];
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n > 0){
            book[n] = 1;
        }
        char ch;
        ch = getchar();
        if(ch == '\n'){
            for(int i = 1; i < 1<<28; i++){
                if(!book[i]){
                    cout << i << endl;
                    break;
                }
            }
            memset(book, 0, sizeof(book));
        }
    }
    return 0;
}
