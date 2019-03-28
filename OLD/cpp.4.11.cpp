/*************************************************************************
    > File Name: cpp.4.11.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 17:48:09 2018
 ************************************************************************/

#include<iostream>
using namespace std;
struct inflatable{
	char name[20];
	float volume;
	double price;
};

int main(){
	inflatable guest = {
		"G G",
		1.88,
		29.99
	};
	inflatable pal = {
		"A A",
		3.12,
		32.99
	};
	cout << "list" << guest.name
		<< " and " << pal.name << endl;
	cout << "Money:"
		<< guest.price + pal.price << endl;
	return 0;
}

