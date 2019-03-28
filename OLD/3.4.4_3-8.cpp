/*************************************************************************
    > File Name: 3.4.4_3-8.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep 18 19:45:02 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 3005;
int a[N], v[N];
int main(){
	int n, m, cnt;
	while(scanf("%d%d", &n, &m) != EOF){
		cnt = 0;
		memset(v, 0, sizeof(v));
		printf("%d / %d = %d.", n, m, n/m);
		n = n % m;
		while(!v[n]){
			a[++cnt] = (n * 10) / m;
			v[n] = cnt;
			n = n * 10 % m;
		}
		for(int i = 1; i < cnt && i <= 50; i++){
			if(i == v[n])  printf("(");
			printf("%d",a[i]);
			if(i == 50)  printf("...");
		}
		printf(")\n%d = number of\n\n", cnt - v[n] + 1);
	}
	return 0;
}
