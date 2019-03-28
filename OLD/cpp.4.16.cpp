/*************************************************************************
    > File Name: cpp.4.16.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 20:08:29 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int higgens = 5;
	int * pt = &higgens;
	cout << "value of higgens = " << higgens
		<< "; Address of higgens = " << &higgens << endl;
	cout << "value of *pt = " << *pt
		<< "; value of pt = " << pt << endl;
	return 0;
}
