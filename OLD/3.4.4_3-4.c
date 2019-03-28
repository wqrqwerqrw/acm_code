/*************************************************************************
    > File Name: 3.4.4_3-4.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep  8 19:13:46 2018
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
	int n,len,i,j;
	char carr[1001];
	while(scanf("%d", &n) != EOF){
		while(n--){
			scanf("%s", carr);
			len = strlen(carr);
			for(i = 2; i <= len; i++){
				if (len % i == 1){
					for(j = 2; j < len; j++){
						if (carr[j] != carr[j%i])  break;
					}
					if (j == len){
						printf("%d\n",i);
						break;
					}
				}
			}
			if (n)  printf("\n");
		}
	}
	return 1;
}
