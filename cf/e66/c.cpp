/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月06日 星期四 00时08分19秒
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
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const nmax = 2e5 + 5;
int n, k;
int a[nmax];
void getsum(int in){
    int ret = 0;
    for(int i = 0; i < n; i++){
        ret += abs(a[i] - in);
    }
    return ret;
}
bool c(int in){
    if(getsum(in) > sum)
}
int main(){
    iofuck;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int lb = a[0], ub = a[n - 1];
        int mid;
        while(ub - lb > 1){
            mid = (lb + ub) / 2;
            if(c(mid)){
                ub = mid - 1;
            }else{
                lb = mid + 1;
            }
        }
        cout << c << endl;
    }
    return 0;
}
