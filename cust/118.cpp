/*************************************************************************
    > File Name: 118.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 10:20:44 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	while(cin >> s){
		int num = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1')  num++;
		}
		cout << num << endl;
	}
	return 0;
}
