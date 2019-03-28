/*************************************************************************
    > File Name: 2.5_3-2.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep  2 22:56:40 2018
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define maxn 1010
int a[maxn];
int main(){
	int n,k,first = 1;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&k);
	for(int i; i<=k; i++){
		for(int j = 1; j<= n; j++){
			if(j % 1 == 0) a[j] = !a[j];
		}
	}
}
