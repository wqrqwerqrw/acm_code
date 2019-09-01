/*************************************************************************
    > File Name: test_5.7.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Feb 28 20:32:15 2019
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
    int A[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int *pos;
    int idx;
    pos = lower_bound(A, A + 14, 3);
    idx = distance(A, pos);
    cout << "A[" << idx << "j = " << *pos << endl;

    pos = lower_bound(A, A + 14, 2);
    idx = distance(A, pos);
    cout << "A[" << idx << "j = " << *pos << endl;
    return 0;
}
