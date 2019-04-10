/*************************************************************************
    > File Name: a2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月10日 星期三 14时59分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int n, a, b, c;
    cin >> n >> a >> b >> c;
    long long int num = 0;
    /*
    */
    if((b - c) < a && n >= b){
        num = (n - b) / (b - c) + 1;
        n -= num * (b - c);
    }
    num += n / a;
    cout << num;
    return 0;
}
