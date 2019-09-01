/*************************************************************************
    > File Name: cust.26.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 21 17:39:01 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0){
			cout << "headmaster" << endl;
		}else{
			cout << "love_me_again" << endl;
		}
	}
	return 0;
}
