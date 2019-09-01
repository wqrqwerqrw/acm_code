/*************************************************************************
    > File Name: cpp.4.13.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 15 18:23:43 2018
 ************************************************************************/

#include<iostream>
using namespace std;
struct inflatable{
	char name[20];
	float volume;
	double price;
};
int main(){
	inflatable guests[2] = {
		{"bambi", 0.5, 21.99},
		{"godzilla", 2000, 565.99}
	};

	cout << "The guests " << guests[0].name << " and " << guests[1].name
		<< "\nhave a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet.\n";
	return 0;
}
