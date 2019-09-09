/*************************************************************************
    > File Name: 2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 14时51分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    string in;
    while(t--){
        cin >> in;
        if(in[0] != ')' || in[in.length() - 1] != '>') {
            cout << "OMG" << endl;
            continue;
        }
        bool flag = 0;
        int ans = 0;
        for(int i = 1; i < in.length() - 1; i++){
            if(in[i] != '=') {
                flag = 1;
                break;
            }
            ans++;
            if(ans > 15) {
                flag = 1;
                break;
            }
        }
        if(flag) cout << "OMG" << endl;
        else{
            if(ans <= 5) cout << "RABBIT" << endl;
            else cout << "DONKEY" << endl;
        }
    }
    return 0;
}
