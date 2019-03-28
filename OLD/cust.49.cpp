/*************************************************************************
    > File Name: cust.49.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 20 20:07:14 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int x, y;
	while(cin >> x >> y){
		char show[x][y];
		for (int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				cin >> show[i][j];
			}
		}
		for(int i = x-1; i >= 0; i--){
			for(int j = y-1; j >= 0; j--){
				cout << show[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
