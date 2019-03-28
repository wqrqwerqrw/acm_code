/*************************************************************************
    > File Name: stl_lower_bound.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月28日 星期四 18时54分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int pos = lower_bound(a, a + 5, 3) - a;
    cout << pos << endl;
    cout << a[pos] << endl;

    vector<int> v;
    for(int i = 4;i >= 0; i--){
        v.push_back(2 * i);
    }
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 3, greater<int>());
    cout << *it << endl;
    return 0;
}
