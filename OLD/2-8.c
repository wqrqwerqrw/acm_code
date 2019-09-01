/*************************************************************************
    > File Name: 2-8-2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep  1 16:05:24 2018
 ************************************************************************/

#include<stdio.h>
int main (){
	const int MOD = 1000000;
	int n;
	int S = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		int fact = 1;
		for(int j = 1; j <= n;j++){
			fact = (fact * j) % MOD;
		}
		S = (S + fact) % MOD;
	}
	printf("%d", n);
	return 0;
}
