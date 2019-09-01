/*************************************************************************
    > File Name: 2-9.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep  1 16:47:33 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int x,n=0,min,max,s=0;
	while(scanf("%d",&x)==1,min = max = x){
		if (x = 0) break;
		s+=x;
		if(x<min) min=x;
		if(x>max) max=x;
		n++;
	}
	printf("%d %d %.3f",min,max,(double)s/n);
	return 0;
}
