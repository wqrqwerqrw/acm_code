/*************************************************************************
    > File Name: 108.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 14:03:11 2018
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a, b, c;
	while(cin >> a >> b >> c){
		double PI = 3.1415926;
		double out;
		out = 0.5 * a * b * sin(PI * c / 180);
		printf("%.2lf\n", out);
	}
	return 0;
}
