/*************************************************************************
    > File Name: 2.5_2-4.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep  2 07:05:58 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	long long int n,m;
	double s;
	while(scanf("%lld%lld",&n,&m)){
		if(n == 0 && m == 0)
			break;
		if(n > m)
			printf ("wrong putin");
		for (n;n <= m;n++){
			int di = n*n;
			s += 1/(double)di;
		}
		printf ("%.5f",s);
	}
}
