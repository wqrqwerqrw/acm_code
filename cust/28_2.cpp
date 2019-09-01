/*************************************************************************
    > File Name: 28_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Thu Oct 25 10:06:03 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool flag(int now, int aim, int *i, int* arr){
    int n = 0;
    do{
        if(aim % 10 == 1){
            aim = (aim - 1) / 10;
            arr[n] = aim;
            n++;
        }
        else if(aim % 2 == 0){
            aim /= 2;
            arr[n] = aim;
            n++;
        }
        else{
            return false;
        }
    }while(aim > now);
    *i = n;
    if(aim == now){
        return true;
    }
    return false;
}
int main(){
    int now, aim;
    while(cin >> now >> aim){
        int *i;
        i = new int;
        *i = 0;
        int arr[1000];
        if(flag(now, aim, i, arr)){
            int n = *i;
            cout << "YES" << endl;
            cout << n + 1 << endl;
            for(n - 1; n >= 0; n--){
                cout << arr[n];
                if(n != 0)  cout << " ";
            }
        }else{
            cout << "NO" << endl;
        }
        cout << endl;
        delete i;
    }
    return 0;
}
