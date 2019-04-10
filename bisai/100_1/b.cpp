/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月10日 星期三 15时43分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string a, b;
    cin >> a >> b;
    int minn = 0x3f3f3f3f;
    int n = 1;
    for(int i = 1; i < b.length(); i++){
        if(b[i] == b[i - 1]) n++;
            if(b[i] != b[i - 1]){
            if(n < minn)  minn = n;
            n = 1;
        }
    }
    int out = 0;
    if(b.length() > a.length()) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < a.length() - b.length() + 1; i++){
        bool flag = 1;
        int j;
        for(j = 0; j < b.length(); j++){
            if(b[j] != a[i + j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            i += b.length() - 1;
            out += 1;
        }
    }
    cout << out;
    return 0;
}
