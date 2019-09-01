/*************************************************************************
    > File Name: 107.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Sep 27 12:29:20 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int in[4];
		for(int i = 0; i < 4; i++)
			cin >> in[i];
		sort(in, in+4);
		for(int i = 0; i < 4; i++){
			if(i != 0)  cout << " ";
			cout << in[i];
		}
		cout << endl;
	}
	return 0;
}
