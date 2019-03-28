/*************************************************************************
    > File Name: 1076A.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Nov 13 07:33:57 2018
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
    string s;
    int n;
    cin >> n >> s;
    bool flag = true;
    for(int i = 0; i < n-1; i++){
        if(s[i] > s[i+1]){
            s.erase(i, 1);
            flag = false;
            break;
        }
    }
    if(flag) s.erase(n-1, 1);
    cout << s;
    return 0;
}
