/************************************************************************
    > File Name: 3.4.4_3-5.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep  9 19:19:41 2018
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define maxn 100
int left, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch){
	int bad = 1;
	for(int i = 0; i < strlen(s); i++)
		if(s[i] == ch){
			left--;
			s[i] = ' ';
			bad = 0;
		}
	if (bad)  --chance;
	if (!chance)  lose = 1;
	if (!left)  win = 1;
}

int main(){
	int rnd;
	while (scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1){
		printf("Round:%d", rnd);
		win = lose = 0;
		left = strlen(s);
		chance = 7;
		for (int i = 0; i < strlen(s2); i++){
			guess(s2[i]);
			if(win || lose)  break;
		}
		if(win)  printf("You win.\n");
		if(lose)  printf("You lose.\n");
		else  printf("You clicked out.\n");
	}
	return 0;
}
