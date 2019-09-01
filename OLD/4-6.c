/*************************************************************************
    > File Name: 4-6.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 14 19:42:07 2018
 ************************************************************************/

#include<stdio.h>
void swap(int* a; int* b){
	int t = *a; *a = *b; *b = t;
}
int main(){
	int a = 3, b = 4;
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}
