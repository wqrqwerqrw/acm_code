/*************************************************************************
    > File Name: 1076C_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Nov 13 08:45:55 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long double ld;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ld d;
        cin >> d;
        ld a = (d + sqrt(d * d - 4 * d))/ 2;
        ld b = (d - sqrt(d * d - 4 * d)) / 2;
        cout.precision(11);
        if(a >= 0 && b >= 0){
            cout << fixed << "Y " << a << " " << b << endl; 
        }else{
            cout << "N" << endl;
        }
    }
    return 0;
}
// asdfa
