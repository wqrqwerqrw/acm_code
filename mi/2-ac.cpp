/*************************************************************************
    > File Name: 2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月31日 星期日 17时57分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int book[1000];
int main(){
    int in;
    while(cin >> in){
        book[in]++;
    }
    for(int i = 0; i < 300; i++){
        if(book[i] == 1)
            cout << i << " ";
    }
    return 0;
}
