/*************************************************************************
    > File Name: 2-3.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Aug 31 14:44:19 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	for (int x = 31;;x++){
		int n = x * x;
		if (n < 1000) continue;
		if (n > 9999) break;
		int hi = n / 100;
		int lo = n % 100;
		if(hi/10 == hi%10 && lo/10 == lo%10) 
			cout << n << endl;
	}
}
