/*************************************************************************
    > File Name: 3.3_3-6.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep  4 16:26:05 2018
 ************************************************************************/

#include<stdio.h>
char s[] = "`12334567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(){
	int i, c;
	while((c = getchar()) != EOF) {
		for (i=1; s[i] && s[i] != c; i++);
		if(s[i]) putchar(s[i-1]);
		else putchar(c);
	}
	return 0;
}
