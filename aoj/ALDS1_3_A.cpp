/*************************************************************************
    > File Name: ALDS1_3_A.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Nov 12 18:03:15 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>

using namespace std;

int top, S[1000];

void push(int x){
    S[++top] = x;
}
int pop(){
    top--;
    return S[top + 1];
}
int main(){
    int a, b;
    top = 0;
    char in[100];
    while(cin >> in){
        if(in[0] == '+'){
            b = pop();
            a = pop();
            push(a + b);
        }else if(in[0] == '-'){
            b = pop();
            a = pop();
            push(a - b);
        }else if(in[0] == '*'){
            b = pop();
            a = pop();
            push(a * b);
        }else{
            push(atoi(in));
        }
    }

    cout << pop() << endl;
    return 0;
}
