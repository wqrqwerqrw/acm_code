/*************************************************************************
    > File Name: 2-3.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep  2 06:32:23 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int a,n,b;
	scanf("%d",&a);
	for(a,b=0;a>=1;a--,b++){
		n = 2 * a - 1;	
		for(int i = 1;i <= b;i++){
			printf(" ");
		}
		for(int i = 1;i <= n;i++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
