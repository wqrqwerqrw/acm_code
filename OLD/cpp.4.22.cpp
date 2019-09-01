/*************************************************************************
    > File Name: cpp.4.22.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep 16 16:03:07 2018
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
char * getname(void);
int main(){
	char * name;

	name = getname();
	cout << name << " at " << (int *) name << endl;
	delete [] name;

	name = getname();
	cout << name << " at " << (int *) name << endl;
	delete [] name;
	return 0;
}

char * getname(){
	char temp[80];
	cout << "Enter last name: ";
	cin >> temp;
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);

	return pn;
}
