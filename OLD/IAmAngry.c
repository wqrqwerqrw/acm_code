/*************************************************************************
    > File Name: IAmAngry.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep  4 20:57:18 2018
 ************************************************************************/

#include<stdio.h>
int s = 0;
int jiami(int in){
	long int squ = in * in;
	s += 8;
	int out = 0;
		for (int i = 0; i < 6; i++){
			if(i = 2){
				out += squ % 10;
			}else if(i = 3){
				out += squ % 10 * 10;
			}else if(i = 4){
				out += squ % 10 * 100;
			}else if(i = 5){
				out += squ % 10 * 1000;
			}
			squ = squ / 10;
		}
	s += 4;
	return out;
	//if (out = 0)  return s;
	//jiami(out,s);
}
int main(){
	int in;
	while(scanf("%d",&in) != EOF){
		s = 4;
		printf("%d",jiami(in));
	}
	return 0;

}
