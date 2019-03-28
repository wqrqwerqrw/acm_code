/*************************************************************************
    > File Name: 2-8.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep  1 15:38:34 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	const int MOD = 1000000;
	int n,S = 0;
	cin >> n;
	if (n>25) n =25;
	for (int i = 1;i <= n;i++){
		int fact = 1;
		for(int j  = 1;j <= i;j++){
			fact = (fact * j) % MOD;
		}
	S = (S + fact) % MOD;
	}
	cout << S << endl;
	return 0;
}
