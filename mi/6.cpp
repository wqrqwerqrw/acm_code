/*************************************************************************
    > File Name: 6.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年03月31日 星期日 20时02分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string in;
    while(cin >> in){
        string str[3];
        int za = 0, zb = 0, zc = 0;
        int kase = 0;
        for(int i = 0; i < in.length(); i++){
            if(in[i] == ',') {
                str[kase].append(1, ',');
                kase++;
                continue;
            }
            str[kase].append(1, in[i]);
        }
        string a = str[0];
        string b = str[1];
        string c = str[2];
        bool flag = false;
        int next = 1;
        for(;;){
            if(za == a.length() - 1 && zb == b.length() - 1){
                flag = true;
                break;
            }
            if(next == 1){
                if(a[za] == c[zc]){
                    next = 1;
                    za++, zc++;
                }else if(b[zb] == c[zc]){
                    next = 2;
                    zb++, zc++;
                }else{
                    break;
                }
            }else{
                if(b[zb] == c[zc]){
                    next = 2;
                    zb++, zc++;
                }else if(a[za] == c[zc]){
                    next = 1;
                    za++, zc++;
                }else{
                    break;
                }
            }
        }
        if(flag) cout << "true" << endl; 
        else cout << "false" << endl;
    }
    return 0;
}
