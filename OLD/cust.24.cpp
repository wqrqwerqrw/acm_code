/*************************************************************************
    > File Name: cust.24.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 21 17:44:14 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	while(cin >> s){
		int one = 0;
		int zero = 0;
		bool ifis = true;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1'){
				one++;
				zero = 0;
			}
			if(s[i] == '0'){
				zero++;
				one = 0;
			}
			if(one == 7 || zero == 7){
				ifis = false;
				break;
			}
		}
		if(ifis){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	return 0;
}
