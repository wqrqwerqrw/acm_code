/*************************************************************************
    > File Name: h.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Fri Oct 26 22:07:52 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct tree{
    int x;
    int y;
    int num = -1;
};
double qiujv(int x1, int y1, int x2, int y2){
    return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}
void move(tree* tree, int n, double* jvli, int k, int i){
    for(int j = i + 1; j < n; j++){
        if(tree[j].num == -1){
            if(*(jvli+i*n+j) <= k){
                tree[i].num = i;
                tree[j].num = i;
                move(tree, n, (double*)jvli, k, j);
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        tree tree[n];
        double jvli[n][n];
        for(int i = 0; i < n; i++){
            cin >> tree[i].x >> tree[i].y;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                jvli[i][j] = qiujv(tree[i].x, tree[i].y, tree[j].x, tree[j].y);
            }
        }
        for(int i = 0; i < n; i++){
            if(tree[i].num == -1){
                move(tree, n, (double*)jvli, k, i);
            }
        }
        int out = 0;
        for(int i = 0; i < n; i++){
            if(tree[i].num == -1) out++;
        }
        cout << out + 1 << endl;
    }
    return 0;
}
