/*************************************************************************
    > File Name: 3.2_3-4_test1.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Sep  3 22:35:27 2018
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
	char s[20], buf[99];	
	scanf("%s",s);
	buf[0] = 775;
	if(strchr(s,buf[0]) == NULL)
		printf ("yes");
	printf("%s",buf[0]);
}
