/*************************************************************************
    > File Name: ALDS1_2_B.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Oct 28 10:11:43 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define N 100
using namespace std;

int main(){
    int n;
    int a[N+1];
    int num = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        int t = a[i];
        a[i] = a[minj];
        a[minj] = t;
        if(minj != i) num++;
    }
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << num << endl;
    return 0;
}
