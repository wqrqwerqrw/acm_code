/*************************************************************************
  > File Name: 3.2.1-poj-3061.cpp
  > Author: Wqr_
  > Mail: xueduanwei@126.com 
  > Created Time: 2019年04月28日 星期日 14时04分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, s;
int a[101000];
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 0; i < n; i++){
            scanf("%d", a + i);
        }
        int res = n + 1;
        int l = 0, r = 0, sum = 0;
        for(;;){
            while(r < n && sum < s){
                sum += a[r++];
            }
            if(sum < s) break;
            res = min(res, r - l);
            sum -= a[l++];
        }
        if(res > n){
            res = 0;
        }
        cout << res << endl;
    }
    return 0;
}
