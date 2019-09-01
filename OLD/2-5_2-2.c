/*************************************************************************
    > File Name: 2-5_2-2.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep  2 06:19:20 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int a,b,c,Case = 1;
	while (scanf("%d%d%d",&a,&b,&c)!= EOF){
		int i;
		for(i=10;i<=999;i++){
			if(i%3 == a && i%5 == b && i%7 == c){
				printf("Case: %d : %d",Case++,i);
				break;
			}
		}
		if (i > 100){
				printf("Case: %d : No answer",Case++);
		}
	}
	return 0 ;
	
}
