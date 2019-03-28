/*************************************************************************
    > File Name: k_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 20:43:29 2018
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
    string in;
    while(cin >> in){
        int num0 = 0, num1 = 0;
        for(int i = 0; i < in.size(); i++){
            if(in[i] == '0') num0++;
            else num1++;
        }
        if(num0 > num1) cout << num1 << endl;
        else cout << num0 << endl;
    }
    return 0;
}
