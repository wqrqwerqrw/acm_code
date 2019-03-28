/*************************************************************************
    > File Name: 1076C.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Tue Nov 13 08:17:05 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void jie(double d, double root){
    double a1, a2;
    a1 = (d + sqrt(root)) / 2;
    a2 = (d - sqrt(root)) / 2;
    if((a1 < 0 && a2 < 0)){
        cout << "N";
        return;
    }else{
        if(a1 > 0 && a2 < 0){
            double b = d - a1;
            if(b < 0){
                cout << "N" << endl;
                return;
            }else{
                cout << "Y ";
                printf("%.8lf %.8lf", a1, b);
                //cout << a1 << " " << b << endl;
                return ;
            }
        }
        if((a2 > 0 && a1 > 0)){
            double b1 = d - a1;
            double b2 = d - a2;
            if(b1 < 0 && b2 < 0){
                cout << "N" << endl;
                return;
            }else{
                if(b2 > b1){
                    cout << "Y ";
                    printf("%.8lf %.8lf", a2, b2);
                    //cout << a2 << " " << b2 << endl;
                }else{
                    cout << "Y ";
                    printf("%.8lf %.8lf", a1, b1);
                    //cout << a1 << " " << b1 << endl;
                }
            }
        }
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        double d;
        cin >> d;
        double root = d * d - 4 * d;
        if(root < 0){
            cout << "N" << endl;
            continue;
        }else{
            jie(d, root);
        }
    }
    return 0;
}
