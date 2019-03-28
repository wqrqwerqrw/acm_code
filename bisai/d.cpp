/*************************************************************************
    > File Name: d.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 19:08:47 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    int t1 = t;
    int sc[1001];
    int s = 0;
    while(t--){
        int n, m;
        cin >> n >> m;
        //if(m == 0 || n == 0){
         //   sc[s] = 0;
          //  s++;
           // break;
        //}
        double ifis = m / (double)2;
        int sc2 = 0;
        for(int i = 0; i < n; i++){
            double renshu = 0;
            for(int j = 0; j < m; j++){
                int a;
                cin >> a;
                if(a == 1) renshu++; 
            }
            if(renshu > ifis){
                sc2++;
            }
            renshu = 0;
        }
        sc[s] = sc2;
        s++;
    }
    for(int i = 0; i < t1; i++){
        cout << sc[i];
        if(i != t1 - 1) cout << endl;
    }
    return 0;
}
