/*************************************************************************
    > File Name: 4.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Nov  2 07:20:05 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct pe{
    int num;
    bool ifis = false;
}pe[1000];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n - m; i++){
            pe[i].num = i + m;
        }
        for(int i = n - m; i < n; i++){
            pe[i].num = i - (n - m);
        }
        int num = 0;
        int next = pe[0].num;
        pe[0].ifis = true;
        num++;
        for(int i = 0; i < n; i++){
            if(pe[next].ifis == true){
                cout << "NO ";
                cout << num << endl;
                break;
            }else{
                num++;
                pe[next].ifis = true;
                next = pe[next].num;
            }
            if(num == n){
                cout << "YES" << endl;
                break;
            }
        }
    }
    return 0;
}
