/*************************************************************************
    > File Name: hcf.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月28日 星期四 19时15分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int hcf(int a, int b){
    int r = 0;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int a, b;
    while(cin >> a >> b){
        int num = hcf(a, b);
        cout << num << endl;
    }
    return 0;
}

