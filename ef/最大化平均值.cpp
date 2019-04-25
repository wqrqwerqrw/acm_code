/*************************************************************************
    > File Name: 最大化平均值.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月22日 星期一 19时43分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
int w[100100], v[100100];
double y[100100];
bool c(double x){
    for(int i = 0; i < n; i++){
        y[i] = v[i] - x * w[i];
    }
    sort(y, y + n);

    double sum = 0;
    for(int i = 0; i < k; i++){
        sum += y[n - 1 - i];
    }

    return sum >= 0;
}
int main(){
    while(cin >> n >> k){
        for(int i = 0; i < n; i++){
            scanf("%d %d", w + i, v + i);
        }
        double lb = 0, ub = 99999999;
        for(int i = 0; i < 100; i++){
            double mid = (lb + ub) / 2;
            if(c(mid)) lb = mid;
            else ub = mid;
        }
        printf("%.2f\n", ub);
    }
    return 0;
}
