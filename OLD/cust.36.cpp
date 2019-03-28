/*************************************************************************
    > File Name: cust.36.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 22 21:10:25 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int in[4];
		for(int i = 0; i <= 3; i++){
			cin >> in[i];
		}
		int big[2];
		int a = 0;
		int b = 0;
		bool ifis = false;
		for(int i = 0; i <= 3; i++){
			if(in[i] > a)  a = in[i];
		}
		for(int i = 0; i <= 3; i++){
			if(in[i] == a) {
				in[i] = 0;
				break;
			}
		}
		for(int i = 0; i <= 3; i++){
			if(in[i] == a) ifis = true;
		}
		for(int i = 0; i <= 3; i++){
			if(in[i] > b && in[i] < a)  b = in[i];
		}
		if(ifis == true)  b = a;
		cout << a + b << endl;
	}
}
