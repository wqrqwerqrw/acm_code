/*************************************************************************
    > File Name: 3.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月25日 星期四 13时57分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
ll p(ll a, ll n){
    ll ans = 1;
    while(n){
        if(n&1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}
bool c(ll r, ll k){
    if((1 - p(k, r + 1)) / (1 - k) >= n) return 1;
    else return 0;
}
bool judge(ll r, ll k){
    return (1 - p(k, r + 1)) / (1 - k) == n;
}
int main(){
    while(cin >> n){
        ll min = 1<<30;
        ll minr = 1<<30;
        ll mink = 1<<30;
        for(int i = 44; i >= 1; i--){
            ll lb = 2, ub = 0x3f3f3f3f, mid;
            while(ub - lb > 1){
                mid = (lb + ub) >> 1;
                if(c(i, mid)) ub = mid; 
                else lb = mid;
                cout << lb << " " << mid << " " << ub << endl;
                if(judge(i, ub)) break;
            }
            ll ans = ub;
            if(i * ans <= min && judge(i, ans)){
                if((i * ans == min)){
                    if(i < minr){
                        minr = i;
                        mink = ans;
                        min = i * ans;
                    }
                }
                else{
                    minr = i;
                    mink = ans;
                    min = i * ans;
                }
            }
        }
        cout << minr << " " << mink << endl;
    }
    return 0;
}

