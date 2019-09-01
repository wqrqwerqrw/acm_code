/*************************************************************************
    > File Name: 3.4.4_4-9.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 19 20:29:36 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string s, t;
int main(){
	while(cin >> s >> t){
		int i = 0;
		for(int j = 0; j <= t.size(); j++){
			if(s[i] == t[j])  i++;
			if(i == s.size())  break;
		}
		printf("%s\n", i == s.size() ? "Yse" : "No");
	}
	return 0;
}
