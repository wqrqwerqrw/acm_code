/*************************************************************************
    > File Name: 3.4_3-1.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep  5 15:30:42 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int c, i = 0, wh = 1, score = 0;

	while ((c = getchar()) != EOF){
		if (c == 'O' && wh == 1){
			i++;
			score += i;
		}else if(c == 'O'){
			i = 1;
			score += i;
			wh = 1;
		}
		if (c == 'X')  
			wh = 0;
	}
	printf ("%d",score);
	return 0;
}
