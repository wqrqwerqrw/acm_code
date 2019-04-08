/*************************************************************************
    > File Name: 588b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月07日 星期日 19时38分09秒
 ************************************************************************/

#include<iostream>      
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int minn = 1<<30;
    int sum = 0;
    int a, b;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        if(b < minn) minn = b;
        sum += a * minn;
    }
    cout << sum;
    return 0;
}
