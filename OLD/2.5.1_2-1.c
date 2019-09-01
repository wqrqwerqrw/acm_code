/*************************************************************************
    > File Name: 2.5.1_2-1.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep  1 22:12:09 2018
 ************************************************************************/

#include<stdio.h>
int main (){
	int i = 100;
	int a,b,c;
	for (i;i<=999;i++){
		a = i / 100;
		b = i % 100 / 10;
		c = i % 10;
		if (i == ((a*a*a) + (b*b*b) + (c*c*c))){
			printf("%d\n",i);
		}
	}
	return 0;
}
