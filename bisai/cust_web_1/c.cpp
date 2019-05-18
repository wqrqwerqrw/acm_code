/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月18日 星期六 14时17分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
int a, b, c;
int main(){
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        //double da = ((double)a / sqrt(1 + c * c));
        //double db = ((double)(b * c) / sqrt(1 + c * c));
        //double da = a * cos(atan(c));
        //double db = b * sin(atan(c));
        double x2 = (double)(a * a * b * b) / (double)((b * b) + (a * a * c * c));
        double y2 = (double)(a * a * b * b * c * c) / (double)((b * b) + (a * a * c * c));
        printf("%.3f %.3f\n", sqrt(x2), sqrt(y2));
    }
    return 0;
}
