/************************************************************************* > File Name: c_2.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: Sat Nov 17 09:39:30 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1000050;
int a[maxn], b[maxn], c[maxn/5];

int main(){
    int n, j, k, m, s;
    long long x, y;
    while(~scanf("%d", &n)){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        x = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &k);
            x += k;
            a[k]++;
            c[i] = k;
        }
        k = 0;
        for(int i = 0; i < n; i++){
            y = x - c[i] * 2;
            a[c[i]]--;
            if(y <= 1000000 && y >= 1 && a[y] > 0){
                b[y] = 1;
            }
            a[c[i]]++;
        }
        for(int i = 0; i < n; i++){
            m = c[i];
            if(b[m]){
                k++;
            }
        }
        printf("%d\n", k);
        for(int i = 0; i < n; i++){
            m = c[i];
            if(b[m]){
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
