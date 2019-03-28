/*************************************************************************
    > File Name: ALDS1_2_A.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Oct 23 09:15:06 2018
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
    cin >> n;
    int in[n];
    int num = 0;
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j = n-1; j > 0; j--){
            if(in[j] < in[j-1]){
                int t = in[j];
                in[j] = in[j-1];
                in[j-1] = t;
                flag = 1;
                num++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << in[i];
    }
    cout << endl;
    cout << num << endl;
    return 0;
}
