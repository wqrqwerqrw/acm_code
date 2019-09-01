/*************************************************************************
    > File Name: cpp.4.7.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 10:14:45 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int mian(){
	char charr1[20];
	char charr2[20] = "jahuar";
	string str;
	string str2 = "pather";

	cout << "Enter a kind of feline: " ;
	cin >> charr1;
	cout << "Enter a kind of feline: ";
	cin >> str1;
	cout << "Here are some felines:" << endl;
	cout << charr1 << " " << charr2 << " "
		<< str1 << "" << str2 << endl;
	cout << "The third letter in " << cahrr2 << " is "
		<< charr[2] << endl;
	cout << "The third letter in " << str2 << " is "
		<< str2[2] << endl;
	return 0;
}

