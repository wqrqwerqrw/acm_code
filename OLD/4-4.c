/*************************************************************************
    > File Name: 4-4.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 14 19:34:24 2018
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int is_prime(int n){
	if(n <= 1)  return 0;
	int m = floor(sqrt(n) + 0.5);
	for(int i = 2; i <= m; i++){
		if (n % i == 0) return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d", &n);
	int ifis = is_prime(n);
	if(ifis){
		printf("%d is a prime", n);
	}else{
		printf("%d is not a prime", n);
	}
	return 0;
}
