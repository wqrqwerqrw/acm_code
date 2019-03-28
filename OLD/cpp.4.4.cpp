/*************************************************************************
    > File Name: cpp.4.4.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 10:03:32 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	const int Arsize = 20;
	char name[Arsize];
	char dessert[Arsize];

	cout << "Enter your name; " << endl;
	cin.get(name, Arsize).get();
	cout << "Enter your favoirte dessert: " << endl;
	cin.getline(dessert, Arsize);
	cout << "I have some delicious " << dessert
		<< " for you, " << name << endl;
	return 0;
}
