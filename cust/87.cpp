/*************************************************************************
    > File Name: 87.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Nov  5 21:41:10 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int qvSi(int in){
    return in % 1000000 / 100;
}
int main(){
    int a;
    while(cin >> a){
        int next = a * a;
        int arr[10000] = {0};
        int arri = 0;
        if(a == 0){
            cout << arri << endl;
            continue;
        }
        arr[arri++] = a;
        a = qvSi(next);
        if(a == 0){
            cout << arri << endl;
            continue;
        }
        arr[arri++] = a;
        for(;;){
            int next = a * a;
            a = qvSi(next);
            if(a == 0) break;
            bool flag = false;
            for(int i = 0; i <= arri; i++){
                if(a == arr[i]){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            arr[arri++] = a;
            cout << a << endl;
        }
        cout << arri << endl;
    }
    return 0;
}
