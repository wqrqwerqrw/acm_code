/*************************************************************************
    > File Name: poj-2456.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月18日 星期四 19时53分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int n, m;
ll x[100100];
bool c(int d){
    int last = 0;
    // 第一个已经确定, 所以i从1开始
    for(int i = 1; i < m; i++){
        int crt = last + 1;
        //当x[crt] - x[last] 的条件不成立时就确定了下一个位置
        while(crt < n && x[crt] - x[last] < d){
            crt++;
        }
        //说明d过大 减小上界
        if(crt == n) return false;
        //确定下一个
        last = crt;
    }
    return true;
}

int main(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            scanf("%d", x + i);
        }
        sort(x, x + n);
        int lb = 0, ub = 0x3f3f3f3f;
        while(ub - lb > 1){
            int mid = (lb + ub) / 2;
            if(c(mid)) lb = mid;
            else ub = mid;
        }
        cout << lb << endl;
    }
    return 0;
}
