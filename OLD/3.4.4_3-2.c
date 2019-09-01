/*************************************************************************
    > File Name: 3.4.4_3-2.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep  7 12:28:36 2018
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
const float C = 12.01;
const float H = 1.008;
const float O = 16.00;
const float N = 14.01;
int main(){
	char ch;
	float numBeAdd;
	float num;
	int ifnumber = 0;
	ch = getchar();
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
	while((ch = getchar()) != EOF){
		float numBeMult;
		if(isdigit(ch)){
			ifnumber = 1;	
			numBeMult = ch - '0';
		}
		if(isalpha(ch))
			ifnumber = 0;	
		if(ifnumber == 0){
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
		}else if(ifnumber == 1){
			num += (numBeAdd * numBeMult);
		}
	}
	if (ifnumber = 0)
		num += numBeAdd;
	printf("%f",num);
}
