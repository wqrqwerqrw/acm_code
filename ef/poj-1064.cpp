/*************************************************************************
    > File Name: poj-1064.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月22日 星期一 18时56分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n, k;
double l[10100];

bool c(double x){
    int num = 0;
    for(int i = 0; i < n; i++){
        num += (int)(l[i] / x);
    }
    return num >= k;
}

int main(){
    double lb = 0, ub = 99999999;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        scanf("%lf", l + i);
    }

    for(int i = 0; i < 100; i++){
        double mid = (lb + ub) / 2;
        if(c(mid)) lb = mid;
        else ub = mid;
    }

    printf("%.2f", floor(ub * 100) / 100);
    return 0;
}
