/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月17日 星期五 23时47分45秒
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
int n;
int a[200200];
int p(int a, int b){
    int t1 = abs(a - b);
    int t2 = abs(a + b);
    if(min(t1, t2) <= min(a, b) && max(t1, t2) >= max(a, b)){
        return 1;
    }
    return 0;
}
int c(int in){
    int lb = in, ub = n;
    int mid;
    int ans;
    while(ub >= lb){
        mid = (lb + ub) >> 1;
        if(p(a[in], a[mid])) ans = mid, lb = mid + 1;
        else ub = mid - 1;
    }
    return ans - in;
}
int main(){
    cin >> n;
    int in;
    for(int i = 0; i < n; i++){
        scanf("%d", &in);
        a[i] = abs(in);
    }
    sort(a, a + n);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += c(i);
    }
    cout << ans << endl;
    return 0;
}
