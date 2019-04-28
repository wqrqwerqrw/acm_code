/*************************************************************************
    > File Name: 3.2-poj-3320.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月28日 星期日 14时16分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n;
int a[1001000];
int main(){
    cin >> n;
    int num = 0;
    map<int, int> mark;
    map<int, int> book;
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
        if(!mark[a[i]]){
            num++;
            mark[a[i]]++;
        }
    }
    int res = n + 1;
    int sum = 0, r = 0, l = 0;
    for(;;){
        while(r < n && sum < num){
            if(!book[a[r]]){
                sum++;
            }
            book[a[r]]++;
            r++;
        }
        if(sum < num) break;
        res = min(res, r - l);
        int tmp = book[a[l]];
        if(tmp <= 1){
            sum--;
        }
        book[a[l]]--;
        l++;
    }
    if(res > n) res = 0;
    cout << res << endl;
    return 0;
}
