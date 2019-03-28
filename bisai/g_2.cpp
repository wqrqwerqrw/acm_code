/*************************************************************************
    > File Name: g_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 20:59:02 2018
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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int tr[n];
        int ifis[n] = {0};
        for(int i = 0; i < n; i++){
            cin >> tr[i];
        }
        for(int i = 0; i < n - 1; i++){
            if(tr[i+1] - tr[i] <= k) ifis[i] = 1;
        }
        int num = 0;
        for(int i = 0; i < n; i++){
            if(ifis[i] == 0) num++;
        }
        cout << num << endl;
    }
}
