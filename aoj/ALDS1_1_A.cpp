/*************************************************************************
    > File Name: ALDS1_1_A.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Oct 23 08:44:17 2018
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
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << in[i];
    }
    cout << endl;
    for(int i = 1; i < n; i++){
        int v = in[i];
        int j = i - 1;
        while(j >= 0 && in[j] > v){
            in[j+1] = in[j];
            j--;
        }
        in[j+1] = v;
        for(int i = 0; i < n; i++){
            if(i) cout << " ";
            cout << in[i];
        }
        cout << endl;
    }
    return 0;
}
