/*************************************************************************
    > File Name: 32.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 26 15:27:55 2018
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		char f;
		int num[9];
		scanf("%d", &num[0]);
		int in = 0;
		int i = 0;
		for(;;){
			f = getchar();
			if(f != '+')  break;
			if(f != '-')  break;
			if(f != '*')  break;
			if(f != '/')  break;
			scanf("%d", &in);
			switch(f){
				case '*':
					num[i] *= in;
					break;
				case '/':
					num[i] /= in;
					break;
				case '+':
					num[++i] += in;
					break;
				case '-':
					num[++i] -= in;
					break;
			}
			if(getchar() == '\n')  break;
		}
		int sum = 0;
		for(;i >= 0; i--){
			sum += num[i];
		}
		cout << sum << endl;
	}
	return 0;
}
