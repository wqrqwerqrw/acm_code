/**********************************************************
    > File Name : poj-3360.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 24 20:45:48
**********************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
bool beat[110][110];
int n, m;
void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(beat[i][j] || (beat[i][k] && beat[k][j]))
                    beat[i][j] = true;
            }
        }
    }
}

int main(){
    while(cin >> n >> m){
        int a, b;
        memset(beat, 0, sizeof(beat));
        for(int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            beat[a][b] = 1;
        }
        floyd();
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int suma = 0;
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(beat[i][j] || beat[j][i]){
                    suma++;
                }
            }
            if(suma == n - 1) sum++;
        }
        cout << sum << endl;
    }
    return 0;
}

