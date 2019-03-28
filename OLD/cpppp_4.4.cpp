/*************************************************************************
    > File Name: cpppp_4.4.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep 11 20:48:29 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	int year;

	cin >> year;
	cin.get();
	cout << year << endl;
	cout << "enter your name: " << endl;
	cin.get(name, ArSize).get();
	// get 不丢弃换行符
	cout << "enter your favorite dessert: " << endl;
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you," << name << ".\n";
	return 0;
}
