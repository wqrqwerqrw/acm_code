/**********************************************************
    > File Name : 1797.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 19 20:58:42
**********************************************************/
// cin竟然直接超时, 海星..
#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#define INF 1<<28
#define MINF -1
using namespace std;
int map[1050][1050];
int book[1050];
int n, k;
int d[1050];
void diji(){
    for(int i = 0; i < n; i++){
        d[i] = map[0][i];
        book[i] = 0;
    }
    d[0] = 0;
    for(int i = 0; i < n; i++){
        int maxd = -1;
        int t;
        for(int j = 0; j < n; j++){
            if(!book[j] && d[j] > maxd){
                maxd = d[j];
                t = j;
            }
        }
        book[t] = 1;
        for(int j = 1; j < n; j++){
            if(!book[j] && d[j] < min(d[t], map[t][j])){
                d[j] = min(d[t], map[t][j]);
            }
        }
    }
}
int main(){
    int kase = 0;
    int num;
    cin >> num;
    while(num--){
        cin >> n >> k;
        int a, b, c;
        memset(map, -1, sizeof(map));
        for(int i = 0; i < k; i++){
            scanf("%d %d %d", &a, &b, &c);
            map[a - 1][b - 1] = c;
            map[b - 1][a - 1] = c;
        }
        diji();
        /*
        for(int i = 0; i < n; i++){
            cout << d[i] << " ";
        }
        */
        printf("Scenario #%d:\n", ++kase);
        printf("%d\n\n", d[n - 1]);
    }
    return 0;
}