/*************************************************************************
    > File Name: 4-1.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 14 19:22:05 2018
 ************************************************************************/

#include<stdio.h>
long long int factorial (int n){
	long long m = 1;
	for(int i = 1; i <= n; i++){
		m *= i;
		return m;
	}
}
long long int C (int n, int m){
	return factorial(n)/(factorial(n) * factorial(n-m));
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%lld", C(n, m));
	return 0;
}
