/*************************************************************************
    > File Name: 3.4.4_3-2_2.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep  7 20:26:36 2018
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
const float C = 12.01;
const float H = 1.008;
const float O = 16.00;
const float N = 14.01;
int main(){
	char ch;
	float num = 0;
	float numBeAdd = 0;
	while((ch = getchar()) != EOF){
		if(isdigit(ch)){
			int numBeMult = ch -'0';	
			numBeAdd *= numBeMult;
			num += numBeAdd;
			numBeAdd = 0;
		}
		if(isalpha(ch)){
			printf("%f",numBeAdd);
			num += numBeAdd;
			switch(ch){
				case 'C':
					numBeAdd = C;
					break;
				case 'H':
					numBeAdd = H;
					break;
				case 'O':
					numBeAdd = O;
					break;
				case 'N':
					numBeAdd = N;
					break;
			}
		}
	}
	num += numBeAdd;
	printf("%f",num);
	return 0;
}
