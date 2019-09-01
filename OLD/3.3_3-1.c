/*************************************************************************
    > File Name: 3.3_3-1.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep  4 16:03:12 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int c, q = 1;
	while(c = getchar() != EOF){
		if (c == '"'){
			printf("%s",q? "左引号": "右引号");
			q = !q;
		}else{
			printf("%c",c);
		}
	}
	return 0;
}
