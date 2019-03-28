/*************************************************************************
    > File Name: stl_gcd.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月28日 星期四 18时52分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int k = __gcd(n, m);
    cout << k;
    return 0;
}
