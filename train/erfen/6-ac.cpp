/*************************************************************************
    > File Name: 6.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月25日 星期四 08时24分39秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
double sh[10100];
const double jingdu = 1e-4;
bool c(double d){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (int)(sh[i] / d);
        if(sum >= k) return 1;
    }
    return 0;
}
int main(){
    while(cin >> n >> k){
        double l = 0, r = 0, min = 0;
        if(!n && !k) break;
        double in;
        double sum;
        for(int i = 0; i < n; i++){
            scanf("%lf", sh + i);
            sum += sh[i];
        }
        r = sum / k;
        //sort(sh, sh + n, greater<double>());
        while((r - l) > jingdu){
            min = (r + l) / 2;
            if(c(min)) l = min;
            else r = min;
        }
        printf("%.2f\n", l);
    }
    return 0;
}
