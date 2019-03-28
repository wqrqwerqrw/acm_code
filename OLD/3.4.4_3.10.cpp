/*************************************************************************
    > File Name: 3.4.4_3.10.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 19 19:42:25 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int w[6];
	int h[6];
	int x, y, z;
	int isx, isy, isz;
	for (int i = 0; i <= 5; i++){
		scanf("%d%d", &w[i], &h[i]);
	}
	x = w[0];
	y = h[0];
	for(int i = 0; i <= 5; i++){
		if(w[i] != x && w[i] != y){
			z = w[i];
			break;
		}
	}
	for(int i = 0; i<= 5; i++){
		if(w[i] == x || h[i] == x){
			isx++;
		}else if(w[i] == y || h[i] == y){
			isy++;
		}else if(w[i] == z || h[i] == z){
			isz++;
		}
	}
	if(isx == 4 && isy == 4 && isz == 4){
		printf("can");
	}else  printf("cant");
}
