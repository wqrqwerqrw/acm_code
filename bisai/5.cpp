/*************************************************************************
    > File Name: 5.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 18:58:45 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int bi(int meng, int hui){
    // return 0:平局 1meng 2hui
    // 剪刀石头布
    if(meng == hui){
        return 0;
    }
    if(meng == 1 && hui == 2){
        return 2;
    }
    if(meng == 1 && hui == 3){
        return 1;
    }
    if(meng == 2 && hui == 1){
        return 1;
    }
    if(meng == 3 && hui == 1){
        return 2;
    }
    if(meng == 2 && hui == 3){
        return 2;
    }
    if(meng == 3 && hui == 2){
        return 1;
    }
}
int p1(){
    return 1;
}
int p2(){
    return 2;
}
int p3(){
    return 3;
}
int p4(int rand){
    if(rand % 3 == 1){
        return 1;
    }else if(rand % 3 == 2){
        return 2;
    }else{
        return 3;
    }
}
int p5(int dui){
    return dui;
}
void bi(int a, int b, int rand){
    int aout = 0, bout = 0;
    int anum = 0, bnum = 0;
    for(int i = 0; i < rand; i++){
        int aoout = aout;
        int boout = bout;
        switch(a){
            case 1:
                aout = p1();
                break;
            case 2:
                aout = p2();
                break;
            case 3:
                aout = p3();
                break;
            case 4:
                aout = p4(i + 1);
                break;
            case 5:
                if(i == 0)
                    aout = 1;
                else
                    aout = p5(boout);
                break;
        }
        switch(b){
            case 1:
                bout = p1();
                break;
            case 2:
                bout = p2();
                break;
            case 3:
                bout = p3();
                break;
            case 4:
                bout = p4(i + 1);
                break;
            case 5:
                if(i == 0)
                    bout = 1;
                else
                    bout = p5(aoout);
                break;
        }
        int jieguo = bi(aout, bout);
        switch(jieguo){
            case 1:
                anum++;
                break;
            case 2:
                bnum++;
                break;
            default:
                break;
        }
    }
    if(anum > bnum){
        cout << "meng" << endl;
    }else if(anum < bnum){
        cout << "hui" << endl;
    }else{
        cout << "tie" << endl;
    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b;
        int rand;
        cin >> rand >> a >> b;
        bi(a, b, rand);
    }
}
