/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月27日 星期六 13时24分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct ope{
    string op;
    int num;
}op[100];
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> op[i].op >> op[i].num;
    }
    int ans = 0;
    for(int j = 1; j <= 100; j++){
        int cur = j;
        for(int i = 0; i < n; i++){
            if(op[i].op[0] == 'A'){
                cur += op[i].num;
            }else if(op[i].op[0] == 'S'){
                if(cur - op[i].num < 0){
                    ans++;
                    break;
                }else{
                    cur -= op[i].num;
                }
            }else if(op[i].op[0] == 'M'){
                cur *= op[i].num;
            }else if(op[i].op[0] == 'D'){
                if(cur % op[i].num != 0){
                    ans++;
                    break;
                }else{
                    cur /= op[i].num;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
