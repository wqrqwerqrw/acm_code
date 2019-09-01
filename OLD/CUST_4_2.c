/*************************************************************************
    > File Name: CUST_4_2.c
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep 11 20:10:51 2018
 ************************************************************************/

#include<stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N,M;
		scanf("%d%d", &N, &M);
		// 1,2,3,4,5,6
		// 0,1,2,3,4,5
		// N = 6, M = 2;
		// 3,4,5,6,1,2
		//  ,4, ,6,1,2
		//  , , ,6, , 2
		//  break;
		int * arr = new int [N];
		for(int i = 0; i <= N-1; i++){
			arr[i] = i + 1;
		}
		for(int i = 0; i <= M-1; i++){
			arr[]
		}
	}
}
