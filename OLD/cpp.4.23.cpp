/*************************************************************************
    > File Name: cpp.4.23.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep 16 16:36:22 2018
 ************************************************************************/

#include<iostream>
using namespace std;
struct antarctica_years_end{
	int year;
};
int main(){
	antarctica_years_end s01, s02, s03;
	s01.year = 1990;
	antarctica_years_end * pa = &s02;
	pa->year = 1999;
	antarctica_years_end trio[3];
	trio[0].year = 2003;
	cout << trio->year << endl;
	const antarctica_years_end * arp[3] = {&s01, &s02, &s03};
	cout << arp[]
}
