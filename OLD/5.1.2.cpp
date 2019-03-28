/*************************************************************************
    > File Name: 5.1.2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 14 20:37:00 2018
 ************************************************************************/

#include<iostream>
using namespace std;
void swap2(int& a, int& b){
	int t = a; a = b; b = t;
}
int main(){
	int a = 3, b = 4;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
