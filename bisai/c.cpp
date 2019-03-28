/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 20:01:41 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool san(int a, int b, int c){
    if(a + b > c && a + c > b && b + c > a){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int out = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int l = j + 1; l < n; l++){
                    if(san(a[i], a[j], a[l]))  out++;
                }
            }
        }
        cout << out << endl;
    }
    return 0;
}
