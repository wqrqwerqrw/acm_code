/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月16日 星期四 15时40分11秒
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
ll a[340];
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        ans = a[0] * a[n - 1];
        bool flag = 0;
        for(int i = 0; i < n; i++){
            if(ans % a[i] != 0) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << -1 << endl;
            continue;
        }
        ll num = 0;
        for(ll i = 2; i <= sqrt(ans); i++){
            if(ans % i == 0){
                num++;
                if(ans / i != i) num++;
            }
        }
        if(num == n)
            cout << ans << endl;
        else 
            cout << -1 << endl;
    }
    return 0;
}
