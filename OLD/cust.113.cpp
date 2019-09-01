/*************************************************************************
    > File Name: cust.113.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 21 15:38:01 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	while(cin >> a >> b >> c){
	int he = a + b;
	if(he > c){
	if (he % c == 0)  cout << "Yes";
	else cout << "No";
	return 0;
	}
	cout << "No";
	}
	return 0;
}
