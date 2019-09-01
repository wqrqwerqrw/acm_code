/*************************************************************************
    > File Name: test.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep 18 21:40:15 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	int f(int x, int y, int z);
	cin >> a >> b >> c;
	c = f(a, b, c);
	cout << c << endl;
	int x;
	cout << x;
	return 0;
}
int f(int x, int y, int z){
	int m;
	if(x < y) m = x;
	else 
	if(z < m) m = z;
	return (m);
}
