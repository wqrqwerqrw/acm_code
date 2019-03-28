/*************************************************************************
    > File Name: ALDS1_3_A_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Jan 28 12:50:57 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main(){
    stack<int> S;
    int a, b, x;
    string s;

    while(cin >> s){
        if(s[0] == '+'){
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a + b);
        }else if(s[0] == '-'){
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a - b);
        }else if(s[0] == '*'){
            a = S.top(); S.pop();
            b = S.top(); S.pop();
            S.push(a * b);
        }else{
            S.push(atoi(s.c_str()));
        }
    }

    cout << S.top() << endl;
    return 0;
}
