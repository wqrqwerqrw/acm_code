/*************************************************************************
    > File Name: 499b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月07日 星期日 20时28分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n, m;
int main(){
    cin >> n >> m;
    map<string, string> mapp;
    string a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        mapp[a] = b;
    }
    string in;
    for(int i = 0; i < n; i++){
        cin >> in;
        if(i) cout << " ";
        if(mapp[in].length() < in.length())
            cout << mapp[in];
        else
            cout << in;
    }
    return 0;
}
