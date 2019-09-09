/*************************************************************************
    > File Name: 1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月18日 星期四 11时46分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int x[100010];
bool c(int d){
    int i;
    int sum = 0, cnt = 1;
    for(int i = 0; i < n; i++){
        if(sum + x[i] <= d)
            sum += x[i];
        else{
            sum = x[i];
            cnt++;
        }
    }
    if(cnt > m)
        return 1;
    else 
        return 0;
}
int main(){
    while(cin >> n >> m){
        int lb, ub;
        lb = ub = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", x + i);
            lb = max(lb, x[i]);
            ub += x[i];
        }
        int min;
        while(lb <= ub){
            min = (lb + ub) >> 1;
            if(c(min)) lb = min + 1;
            else ub = min - 1;
        }
        cout << min << endl;
    }
    return 0;
}
