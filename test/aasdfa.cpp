/*************************************************************************
    > File Name: aasdfa.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月25日 星期四 00时24分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> a;
    for(int i = 0; i < 100; i++){
        a.push_back(i);
    }
    for(auto i : a){
        cout << i << endl;
    }
}
