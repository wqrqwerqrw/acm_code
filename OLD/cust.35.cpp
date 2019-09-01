/*************************************************************************
    > File Name: cust.35.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Sep 22 20:34:06 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if (n == 1 || n > 20){
			cout << 0 << endl;
			continue;
		}
		if (n > 1 && n <= 10){
			int shang = n / 2;
			if (n % 2 == 0){
				cout << (shang - 1) * 16 + 6 << endl;
			}else if(n % 2 == 1){
				cout << (shang - 1) * 16 + 16 << endl;
			}
		}
		if(n > 10 && n < 20){
			cout << 16 * 4 << endl;
		}
		if(n == 20)  cout << 120 << endl;
	}
	return 0;
}
