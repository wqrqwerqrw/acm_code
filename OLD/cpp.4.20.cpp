/*************************************************************************
    > File Name: cpp.4.20.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 21:21:30 2018
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char animal[20] = "bear";
	const char * bird = "wren";
	char * ps;

	cout << animal << " and ";
	cout << bird << endl;
	cout << "Enter a kind of animal; ";
	cin >> animal;

	ps = animal;
	cout << ps << "s!\n";
	cout << "Before using strcpy(): " << endl;
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int* )ps <<endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "After using strcpy();" << endl;
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;
	delete [] ps;
	return 0;
}

