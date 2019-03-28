/*************************************************************************
    > File Name: 1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 18:39:26 2018
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
    while(n--){
        int in;
        cin >> in;
        double out = (20-in) / (double)20;
        out *= 100;
        cout << (int)out << "%" << endl;
    }
    return 0;
}
