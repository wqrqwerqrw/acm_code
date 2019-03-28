/*************************************************************************
    > File Name: 2.4_3-4_test2.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep  4 07:38:53 2018
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
	char buf[99];
	char s[20];
	scanf("%s", s);
	sprintf(buf, "%d%d", 775, 33);
	printf("%d\n", s[0]);
	printf("%d\n", s[1]);
	printf("%d\n", s[2]);
	printf("%d\n", s[3]);
	printf("%d\n", s[4]);
	printf("%d\n", s[5]);
	printf("---------\n")
	printf("%d\n", buf[0]);
	printf("%d\n", buf[1]);
	printf("%d\n", buf[2]);
	printf("%d\n", buf[3]);
	printf("%d\n", buf[4]);
	printf("%d\n", buf[5]);
	printf("%d\n", buf[6]);
	printf("%d\n", buf[7]);
	printf("%d\n", strlen(buf));
	if(strchr(s, buf[0]) != NULL)  
	
	return 0;
}
