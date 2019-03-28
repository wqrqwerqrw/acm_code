/*************************************************************************
    > File Name: m.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 18:45:27 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct w{
    string name;
    char zhong;
};
int main(){
    int n;
    int a, b;
    cin >> n;
    w w[n];
    for(int i = 0; i < n; i++){
        cin >> w[i].name >> w[i].zhong;
        if(w[i].zhong == 'A') a++;
        if(w[i].zhong == 'B') b++;
    }
    int a1 = a;
    int b1 = b;
    cout << "A:";
    for(int i = 0; i < n; i++){
        if(w[i].zhong == 'A'){
            cout << " ";
            cout << w[i].name;
        }
    }
    cout  << endl;
    cout << "B:";
    for(int i = 0; i < n; i++){
        if(w[i].zhong == 'B'){
            cout << " ";
            cout << w[i].name;
        }
    }
    cout  << endl;
    return 0;
}
