/*************************************************************************
    > File Name: cust.48.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Mon Sep 17 19:59:30 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int t;
	int num[t];
	scanf("%d", &t);
	int t2 = t;
	int i = 0;
	while(t--){
		int x;
		scanf("%d", &x);
		float out = x / 20.0;
		out = 1 - out;
		out = out * 100;
		num[i++] = (int)out;
	}
	int j = 0;
	while(t2--){
		printf("%d%%", num[j++]);
	}
	return 0;
}

