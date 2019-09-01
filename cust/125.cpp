#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    string in;
    while(cin >> in){
        string a, b;
        int ban = in.size() / 2;
        for(int i = 0; i < ban; i++){
            a = a + in[i];
        }
        for(int i = ban; i < in.size(); i++){
            b = b + in[i];
        }
        bool flag = false;
        if(b[0] == '0'){
            a = a + "0";
            flag = true;
        }
        cout << a << " ";
        if(flag){
            for(int i = 1; i < b.size(); i++){
                cout << b[i];
            }
        }else{
            cout << b;
        }
        cout << endl;
    }
    return 0;
}
