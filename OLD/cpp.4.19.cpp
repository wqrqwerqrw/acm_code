/*************************************************************************
    > File Name: cpp.4.19.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 20:40:20 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	double wages[3] = {10000.0, 20000.0, 30000.0};
	short stacks[3] = {3, 2, 1};
	double * pw = wages;
	short * ps = &stacks[0];
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "add 1 to the pw pointer:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << endl << endl;

	cout << "pw = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "add 1 to the ps pointer:\n";
	cout << "pw = " << ps << ", *ps = " << *ps << endl << endl;
	
	cout << "access two elements with array notation\n";
	cout << "stacks[0] = " << stacks[0]
		<<", stacks[1] = " << stacks[1] <<endl;
	cout << "access two elements with pointer notation\n";
	cout << "stacks[0]" << stacks[0]
		<< ", stacks[1]" << stacks[1] << endl;
	cout << "access two elements with pointer notation\n";
	cout << "*stacks = " << *stacks
		<< ", *(stacks + 1) = " << *(stacks + 1) << endl;
	cout << sizeof(wages) << " = size of wages array\n";
	cout << sizeof(pw) << " = size of pw pointer\n";
	return 0;
	
}
