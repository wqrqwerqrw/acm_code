/*************************************************************************
    > File Name: hdu-1875.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月04日 星期六 21时10分25秒
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
int n;
int xx[MAX_N], yy[MAX_N];
double mapp[MAX_N][MAX_N];
int f(int in){
    return in * in;
}
double getdis(int i, int j){
    return sqrt(f(xx[i] - xx[j] + f(yy[i] - yy[j])));
}
bool getcost(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) {
                mapp[i][j] = 0;
                continue;
            }
            mapp[i][j] = getdis(i, j);
            if(mapp[i][j] > 1000) return 0;
        }
    }
    return 1;
}
void prim(){

}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> xx[i] >> yy[i];
        }
        if(!getcost()) {
            cout << "oh!" << endl;
            continue;
        }else{
            prim();
        }
    }
    return 0;
}
