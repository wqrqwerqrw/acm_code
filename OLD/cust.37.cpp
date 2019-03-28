/*************************************************************************
    > File Name: cust.37.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 22 21:41:30 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string in;
		int num = 0;
		cin >> in;
		for(int i = 0; i <= n-1; i++){
			if (in[i] == 'A' || in[i] == 'C' || in[i] == 'M') 
				num++;
		}
		cout << num << endl;
	}
	return 0;
}
