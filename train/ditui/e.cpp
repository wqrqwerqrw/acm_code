/*************************************************************************
    > File Name: e.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月06日 星期一 20时59分21秒
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
double y;
double fd(double x){
    return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * x;
}
double f(double x){
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> y;
        double lb = 0, ub = 100;
        double mid;
        while(ub - lb > 1e-7){
            mid = (lb + ub) / 2;
            if(fd(mid) >= y) ub = mid;
            else lb = mid;
        }
        printf("%.4f\n", f(mid));
    }
    return 0;
}
