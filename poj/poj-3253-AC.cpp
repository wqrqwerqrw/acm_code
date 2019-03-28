/*************************************************************************
    > File Name: 3253.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Mar  9 15:31:40 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    vector<int> l;
    cin >> n;
    long long  ans = 0;
    for(int i = 0; i < n; i++){
        int in;
        cin >> in;
        l.push_back(in);
    }
    while(n > 1){
        int mii1 = 0; int mii2 = 1;
        if(l[mii1] > l[mii2]) swap(mii1, mii2);

        for(int i = 2; i < n; i++){
            if(l[i] < l[mii1]){
                mii2 = mii1;
                mii1 = i;
            }else if(l[i] < l[mii2]){
                mii2 = i;
            }
        }

        int t = l[mii2] + l[mii1];
        ans += t;

        if(mii1 == n - 1) swap(mii1, mii2);
        l[mii1] = t;
        l[mii2] = l[n-1];
        n--;
    }

    cout << ans << endl;
    return 0;
}
