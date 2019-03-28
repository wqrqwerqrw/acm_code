/*************************************************************************
    > File Name: 3.4.4_3-9.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Wed Sep 19 21:42:04 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	string s, t;
	while(cin >> s >> t){
		int num = -1;
		bool ifis2 = false;
		for(int i = 0; i < s.size(); i++){
			bool ifis = false;
			for(int j = 0; j < t.size(); j++){
				if(t[j] == s[i] && j > num){
					num = j;
					t[j] = 0;
					ifis = true;
					break;
				}else if(t[j] == s[i] && j < num){
					break;
				}
			}
			if(ifis == true)  ifis2 = true;
			if(ifis == false){
				ifis2 = false;
				break;
			}
		}
		if(ifis2){
			printf("Yes");
		}else  printf("No");
	}
	return 0;
}
