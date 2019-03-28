/*************************************************************************
    > File Name: ALDS1_10_C.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Oct 24 11:18:21 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N = 1000;
int lcs(string a, string b){
    int maxl = 0;
    int m = a.size();
    int n = b.size();
    int c[m+1][n+1];
    a = ' ' + a;
    b = ' ' + b;
    c[0][0] = 0;
    for(int i = 1; i <= m; i++)  c[i][0] = 0;
    for(int i = 1; i <= n; i++)  c[0][i] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j]){
                c[i][j] = c[i - 1][j - 1] + 1;
            }else{
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
            maxl = max(maxl, c[i][j]);
        }
    }
    return maxl;
}

int main(){
    string in1, in2;
    while(cin >> in1){
        int num0, num1;
        for(int i = 0; i < in1.size(); i++){
            if(in1[i] == 0) num0++;
            else num1++;
            if(num0 > num1) cout << num0 << endl;
            else cout << num1 << endl;
        }
    }
    //cout << lcs(in1, in2) << endl;
    return 0;
}
