/*************************************************************************
    > File Name: h.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 16时12分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
long long n, k;
int main(){
    while(cin >> n >> k){
        int ans = 0;
        bool flag = 0;
        int ans1 = 0;
        int x = sqrt(n);
        for(int i = 1; i <= x; i++){
            if(n % i == 0) ans++;
            if(ans == k) {
                cout << i << endl;
                flag = 1;
                break;
            }
        }
        if(!flag){
            if(x * x == n)
                ans = ans * 2 - 1;
            else
                ans *= 2;
            if(ans < k){
                cout << -1 << endl;
                flag = 1;
            }
        }
        if(!flag){
            ans = ans + 1 - k;
            for(int i = 1; i <= x; i++){
                if(n % i == 0){
                    ans1++;
                    if(ans1 == ans){
                        cout << n / i << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
