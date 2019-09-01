/*************************************************************************
    > File Name: cpp.4.17.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 20:16:43 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int * pt = new int;
	*pt = 1001;
	cout << "int ";
	cout << "value = " << *pt << ": location = " << pt << endl;

	double * pd = new double;
	*pd = 10000001.0;

	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "size of *pt = " << sizeof(pt);
	cout << ": size of *pt = " << sizeof(*pt) << endl;
	cout << "size of pd = " << sizeof pd;
	cout << ": size of *pd" << sizeof(*pd) << endl;
	return 0;
}
