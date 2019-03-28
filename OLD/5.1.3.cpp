/*************************************************************************
    > File Name: 5.1.3.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Sep 14 20:44:24 2018
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	string line;
	while(getline(cin, line)){
		int sum = 0, x;
		stringstream ss(line);
		while (ss >> x)  sum += x;
		cout << sum << endl;
	}
	return 0;
}


