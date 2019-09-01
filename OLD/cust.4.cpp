/*************************************************************************
    > File Name: cust.4.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sun Sep 16 17:45:59 2018
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, M;
		int k;
		int num = 0;
		scanf("%d%d", &N, &M);
		if(N == 2 && M == 1){
			cout << "Yes" << endl;
		}else{
		int ren[N];
		for(int i = 0; i <= N-1; i++){
			ren[i] = i + 1;
		}
		int ren_2[M];
		for(int i = 0; i <= M-1; i++){
			ren_2[i] = ren[i];
		}
		for(int i = 0; i <= N-M; i++){
			int shu = N - M - 1;
			ren[i] = ren[i + shu];
		}
//		ren = ren + M;
		for(int i = 0; i <= M-1; i++){
			ren[i+(N-M)] = ren_2[i];
		}
		k = ren[0];
		ren [0] = 0;
		num ++;
		int ifis = 1;
		for(int i = 0; i <= N-2; i++){
			if(ren[k-1] != 0){
				int a = k;
				k = ren[k-1];
				ren[a-1] = 0;
				num++;
			}else{
				ifis = 0;
				break;
			}
		}
		if(ifis){
			cout << "Yes" << endl;
		}else{
			cout << "No " << num - 1<< endl;
		}
		}
	}
	return 0;
}
