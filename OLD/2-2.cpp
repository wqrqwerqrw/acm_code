/*************************************************************************
    > File Name: 2-2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Aug 31 14:37:25 2018
 ************************************************************************/

#include<cmath>
#include<iostream>
using namespace std;
int main(){
	for(int a = 1;a <= 9;a++){
		for(int b = 1;b <= 9;b++){
			int n = a * 1100 + b * 11;
			int m = floor(sqrt(n) + 0.5);
			if (m * m == n){
				cout << n << endl;
			}
		}
	}
}
