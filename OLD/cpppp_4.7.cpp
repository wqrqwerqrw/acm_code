/*************************************************************************
    > File Name: cpppp_4.7.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep 11 21:04:39 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main(){
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "enter a kind of feline: ";
	cin >> charr1;
	cout << "enter another kind of feline: ";
	cin >> str1;
	cout << "Here are some felines: " << endl;
	cout << charr1 << " " << charr2 << " " << str1 << "" << str2
		<< endl;
	cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
	cout << "The third letter in " << str2 << " is " << str2[2] << endl;

	return 0;
}

