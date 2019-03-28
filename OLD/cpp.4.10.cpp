/*************************************************************************
    > File Name: cpp.4.10.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 10:52:04 2018
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	char charr[20];
	string str;
	cout << "Length of string in charr before input: "
		<< strlen (charr) << endl;
	cout << "Lengrh of string in str before input: "
		<< str.size() << endl;
	cout << "Enter a line of text" << endl;
	cin.getline(charr, 20);
	cout << " You entered " << charr << endl;
	cout << "Enter another line of Text" << endl;
	getline(cin, str);
	cout << "You entered " << str << endl;
	cout << "Lengrh of string in charr after input: "
		<< strlen(charr) << endl;
	cout << "Lengrh of string in str after input: "
		<< str.size() << endl;
	return 0;
}

