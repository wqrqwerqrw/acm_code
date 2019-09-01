/*************************************************************************
    > File Name: cust.34.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 22 20:18:26 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int have = 10;
		int m = n - have;
		if(m <= 0)  cout << 0  << endl;
		if(m > 0 && m < 10) cout << 4 << endl;
		if(m == 10)  cout << 16 << endl;
		if(m > 10)  cout << 0 << endl;
	}
	return 0;
}
