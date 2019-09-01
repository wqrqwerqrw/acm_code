/*************************************************************************
    > File Name: cpp.4.21.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep 16 15:55:32 2018
 ************************************************************************/

#include<iostream>
using namespace std;
struct inflatable{
	char name[20];
	float volume;
	double price;
};

int main(){
	inflatable * ps = new inflatable;
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20);
	cout << "Enter volume in cublic feet: ";
	cin << (*ps).volume;
	cout << "Enter price: $";
	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << "cube feet\n";
	cout << "price: $" << ps->price << endl;
	delete ps;
	return 0;
}
