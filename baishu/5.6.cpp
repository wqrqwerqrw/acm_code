/*************************************************************************
    > File Name: 5.6.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Nov 21 14:43:17 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void print(vector<int> v){
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << *it;
    }
    cout << endl;
}

int main(){
    int N = 4;
    vector<int> v;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    print(v);

    vector<int>::iterator it = v.begin();
    *it = 3;
    it++;
    (*it)++;

    print(v);

    return 0;

}
