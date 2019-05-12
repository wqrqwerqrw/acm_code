#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int poww(int in){
    int re = 1;
    for(int i = 0; i < in; i++){
        re *= 10;
    }
    return re;
}
int main(){
    string in;
    string out;
    cin >> in;
    int out_n = 0;
    int ps;
    int e = 0;
    int w = 0;
    for(int i = in.length() - 1; i >= 0; i--){
        if(in[i] == 'e') break;
        e += (in[i] - '0') * poww(w++);
    }
    for(int i = 0; i < in.length() - w - 1; i++){
        if(in[i] == '.') {
            ps = i;
            continue;
        }
        out += in[i];
    }
    if(in[1] == '.' && in[2] == '0' && in[3] == 'e' && in[4] == '0') {
        cout << in[0];
        return 0;
    }
    if(ps + e < out.length()){
        bool flag = 0;
        bool flag2 = 0;
        for(int i = 0; i < out.length(); i++){
            if(i == ps + e) {
                cout << ".";
                flag = 1;
            }
            if(flag){
                cout << out[i];
            }else{
                if(out[i] == '0' && i + 1 == ps + e){
                    cout << out[i];
                    continue;
                }
                if(out[i] != '0' || flag2){
                    cout << out[i];
                    flag2 = 1;;
                }
            }
        }
        cout << endl;
    }else{
        bool flag = 0;
        for(int i = 0; i < out.length(); i++){
            if(out[i] != '0' || flag){
                cout << out[i];
                flag = 1;
            }
        }
        for(int i = 0; i < e - (out.length() - ps); i++){
            cout << '0';
        }
        cout << endl;
    }
    return 0;
}
