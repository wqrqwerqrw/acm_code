/*************************************************************************
    > File Name: cust.76.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 20 20:32:13 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		int a[n];
		bool ifis = true;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i]--;
		}
		int *f(int x[], int y, int z);
		int *b;
		b = f(a, n, n);
		for(int i = 0; i < n; i++){
			if(b[i] > 0){
				ifis = false;
				break;
			}
		}
		if(ifis)  cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
int *f(int x[], int y, int z){
	y--;
	if(y == 0){
		return x;
	}
	bool ifis2 = false;
	for(int i = 0; i < z; i++){
		if(x[i] == 0){
			ifis2 = true;
			break;
		}
	}
	if(ifis2 == true){
		for(int i = 0; i < z; i++){
			x[i]--;
		}
		f(x, y, z);
	}else{
		return x;
	}
}
