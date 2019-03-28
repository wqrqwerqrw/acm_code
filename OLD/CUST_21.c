/*************************************************************************
    > File Name: CUST_21.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep  9 10:47:38 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int n,x,y;
	while(scanf("%d%d%d", &n, &x, &y) != EOF){
		double want = (double)n * (double)y / 100;
		double need = want - x;
		int need2 = need * 10;
		int ifis = 0;
		if (need2 % 10 > 0) {
			need2 = need / 1 + 1;
			ifis = 1;
		}
		if(x > want)  printf("0\n");
		else if(ifis){
			printf("%d\n", need2);
		}else{
			printf("%d\n", need2/10);
		}
	}
	return 0;
}
