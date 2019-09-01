/************************************************************************* > File Name: 2.5_2-5.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep  2 19:54:21 2018
 ************************************************************************/
#include<stdio.h>
int main(){
	int a,b,c,c1 = 1,kase = 1;
	for (;;){
		scanf ("%d%d%d",&a,&b,&c);
		if (a == 0 && b == 0 && c == 0)  break;
		if ((a > 1000000 || b > 1000000) || c > 100)
			printf("Case%d : no answer",kase++);
		for (int i = 1; i <= c; i++){
			c1 *= 10;
		}
		double yv = 0;
		yv = (double)a / (double)b; 
		yv = yv * (double)c1;
		yv = (int)yv % c1;
		yv = (double)yv / (double)c1;
		printf("Case%d : %f",kase++,yv);
	}
	return 0;
}
