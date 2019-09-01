/*************************************************************************
    > File Name: cpp.4.18.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 20:33:44 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	double * p3 = new double [3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] is " << p3[1] << endl;
	p3 = p3 + 1;
	cout << "now p3[0] is " << p3[0] << " and"
		<< "p3[1] is " << p3[1] << endl;
	p3 = p3 - 1;
	delete [] p3;
	return 0;
}
