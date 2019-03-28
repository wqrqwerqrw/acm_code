/*************************************************************************
    > File Name: cpp.4.9.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 10:37:22 2018
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int mian(){
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy(charr1, charr2);

	str1 += " pastr";
	strcat(charr1, " juice");

	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << "the string " << str1 << " contains"
		<< len1 << " characters." << endl;
	cout << " the string " << charr1 << " contains "
		<< len2 << " characters." << endl;

	return 0;
}

