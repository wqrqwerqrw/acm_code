/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Nov 16 22:31:14 2018
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
    int t;
    cin >> t;
    while(t--){
        long long  a, b, k;
        long long wz = 0;
        cin >> a >> b >> k;
        int s = k / 2;
        wz -= b * s;
        wz += (k - s) * a;
        cout << wz << endl;
    }
    return 0;
}
