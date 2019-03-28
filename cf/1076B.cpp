/*************************************************************************
    > File Name: 1076B.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Nov 13 09:19:14 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
typedef unsigned long long ll;
using namespace std;
int main(){
    ll in;
    cin >> in;
    bool ss[200009];
    for(int i = 0; i < 200009; i++){        
        ss[i] = true;
    }
    ss[0] = false;
    ss[1] = false;
    for(int i = 0; i < 200009; i++){
        if(ss[i]){
            for(int j = 2; j * i < 200009; j++){
                ss[j * i] = false;
            }
        }
    }
    bool flag = true;
    for(int i = 2; i <= sqrt(in); i++){
        if(in % i == 0){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "1";
    }else{
        if(in % 2 == 0) cout << in / 2;
        else{
            int x = 1;
            for(int i = 0; i <= sqrt(in); i++){
                if(ss[i] && in % i == 0){
                    x = i;
                    break;
                }
            }
            int y = in / x;
            cout << x * (y - 1) / 2;
        }
    }
    return 0;
}
