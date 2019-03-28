/*************************************************************************
    > File Name: cpp.4.2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 14 21:15:51 2018
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main(){
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "Howdy! I am " << name2;
	cout << "! What is your name?" << endl;
	cin >> name1;
	cout << "Well, " << name1 << ", your name has ";
	cout << strlen (name1) << " letters and is stored" << endl;
	cout << "is an array of " << sizeof(name1) << " bytes.";
	cout << "Your initial is" << name1[0] << endl;
	name2[3] = '\0';
	cout << "Here are thr first 3 characters of my name: ";
	cout << name2 << endl;
	return 0;
}

