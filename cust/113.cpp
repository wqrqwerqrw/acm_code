/*************************************************************************
    > File Name: 113.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 07:30:53 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	while(cin >> a >> b >> c){
		int he = a + b;
		if(he % c == 0)  cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
