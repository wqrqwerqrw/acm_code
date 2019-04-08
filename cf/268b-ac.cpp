/*************************************************************************
    > File Name: 268b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月07日 星期日 19时18分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int in;
    cin >> in;
    int sum = 0;
    sum += in;
    for(int i = 2; i <= in - 1; i++){
        sum += i * (in - i) + 1;
    }
    if(in > 1){
        sum++;
    }
    cout << sum;
    return 0;
}
