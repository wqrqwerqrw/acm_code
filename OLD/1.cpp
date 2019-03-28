/*************************************************************************
    > File Name: 1.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Oct 13 18:51:34 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool bijiao(string in1, string in2, int num){
    bool flag = true;
    int j = 0;
    bool flag2 = true;
    for(int i = 0; j < num;){
        if(in2[i] != in1[j%num]){
            if(!flag2)
                break;
            j++; 
        }else if(in2[i] == in1[j%num]){
            i++;
            j++;
            flag2 = false;
        }else{
            flag = false;
        }
    }
    return flag;
}
int main(){
    int n;
    cin >> n;
    string in[n];
    int num[n];
    int out = 0;
    for(int i = 0; i < n; i++){
        cin >> in[i];
        num[i] = in[i].size();
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(num[i] != num[j])
                continue;
            else if(bijiao(in[i], in[j], num[i])){
                in[i] = "$";
                in[j] = "$";
                num[i] = 0;
                num[j] = 0;
                out++;
            }else{
                continue;
            }
        }
    }
    cout << out;
    return 0;
}
