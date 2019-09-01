/*************************************************************************
    > File Name: cust.75.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 21 13:14:50 2018
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x, y;
	while(cin >> x >> y){
		int stone = y / x;
		int num = stone / 3;
		//double out = num * 0.001 * pow(0.999,(num - 1));
		double out = 1 - pow(0.999,(num));
		printf("%.6f\n", out);
	}
	return 0;
}

