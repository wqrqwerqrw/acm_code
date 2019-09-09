/*************************************************************************
    > File Name: i.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月20日 星期六 15时41分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    string in;
    int k;
    cin >> in >> k;
    int numm = 0;
    int n = in.length();
    for(int i = 0; i < n; i++){
        if(in[i] == '0')
            numm++;
    }
    if(numm >= k){
        int num0 = 0;
        int num = 0;
        for(int i = n - 1; i >= 0; i--){
            if(in[i] == '0') num0++;
            else num++;
            if(num0 == k) break;
        }
        cout << num << endl;
    }else{
        cout << n - 1 << endl;
    }
    return 0;
}
