/*************************************************************************
    > File Name: 3.4_3-4.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Sep  3 22:42:34 2018
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
	int count = 0;
	char s[20],buf[99];
	scanf("%s",s);
	for (int abc = 111; abc <= 999; abc++){
		for (int de = 11; de <= 99; de++){
			int x = abc * (de%10); //个位
			int y = abc * (de/10); //十位
			int z = abc * de;
			sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
			int ok = 1;
			for (int i = 0; i < strlen(buf); i++){
				if (strchr(s, buf[i]) == NULL)  ok = 0;
			}
			if (ok){
				printf("<%d>\n",++count);
				printf("%5d\n",abc);
				printf("x%4d\n",de);
				printf("-----\n");
				printf("%5d\n",x);
				printf("%4d \n",y);
				printf("-----\n");
				printf("%5d\n",z);
			}
		}
	}
	printf ("The number of solution is %d",count);
	return 0;
}
