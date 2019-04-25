/*************************************************************************
    > File Name: 2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月23日 星期二 18时55分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n, f;
double r[10100];
bool c(double d){
    int sum = 0;
    //double have;
    for(int i = 0; i < n; i++){
        sum += (int)(r[i] / d);
        if(sum >= f + 1) return 1;
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> f;
        double ub, lb;
        ub = lb = 0;
        int in;
        for(int i = 0; i < n; i++){
            scanf("%d", &in);
            r[i] = acos(-1) * in * in;
            ub = max(ub, r[i]);
        }
        sort(r, r + n, greater<double>());
        double min;
        while(ub - lb > 1e-7){
            //cout << lb << " " << ub << endl;
            min = (ub + lb) / 2;
            if(c(min)) lb = min;
            else ub = min;
        }
        printf("%.4f\n", min);
    }
    return 0;
}
