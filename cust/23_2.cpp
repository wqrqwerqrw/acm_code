/*************************************************************************
    > File Name: 23_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Sep 25 08:46:08 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		int in[n];
		bool flag;
		for(int i = 0; i < n; i++){
			cin >> in[i];
		}
		int right = 0;
		int a = n;
		for(int i = n-1; i >= 0; i--){
			if(in[i] == a){
				in[i] = 0;
				a--;
				right++;
			}
		}
		cout << n - right << endl;
	}
	return 0;
}

