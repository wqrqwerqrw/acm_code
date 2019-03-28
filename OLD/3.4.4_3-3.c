/*************************************************************************
    > File Name: 3.4.4_3-3.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep  7 21:11:56 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int zero = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;
	char ch;
	while((ch = getchar()) != EOF){
		switch(ch){
			case '0':
				zero++;
				break;
			case '1':
				one++;
				break;
			case '2':
				two++;
				break;
			case '3':
				three++;
				break;
			case '4':
				four++;
				break;
			case '5':
				five++;
				break;
			case '6':
				six++;
				break;
			case '7':
				seven++;
				break;
			case '8':
				eight++;
				break;
			case '9':
				nine++;
				break;
		}
	}
		printf("%d\n",zero);
		printf("%d\n",one);
		printf("%d\n",two);
		printf("%d\n",three);
		printf("%d\n",four);
		printf("%d\n",five);
		printf("%d\n",six);
		printf("%d\n",seven);
		printf("%d\n",eight);
		printf("%d\n",nine);
		return 0;
}
