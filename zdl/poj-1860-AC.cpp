/**********************************************************
    > File Name : poj-1860.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 24 15:43:13
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
struct poin{
    int a, b;
    double r, c;
}expp[220];
int nume;
int n, m, s;
double v;
// 到第[]种货币的最大值
double dis[101];
bool bell(){
    memset(dis, 0, sizeof(dis));
    dis[s] = v;
    for(int i = 0; i < n - 1; i++){
        bool flag = false;
        for(int j = 0; j < nume; j++){
            if(dis[expp[j].b] < (dis[expp[j].a] - expp[j].c) * expp[j].r){
                dis[expp[j].b] = (dis[expp[j].a] - expp[j].c) * expp[j].r;
                flag = true;
            }
        }
        if(!flag) break;
    }
    for (int j = 0; j < nume; j++) {
        if (dis[expp[j].b] < (dis[expp[j].a] - expp[j].c) * expp[j].r) {
            return true;
        }
    }
    return false;
}
int main(){
    while(cin >> n >> m >> s >> v){
        nume = 0;
        int exa, exb;
        double exra, exca, exrb, excb;
        for(int i = 0; i < m; i++){
            scanf("%d %d %lf %lf %lf %lf", &exa, &exb, &exra, &exca, &exrb, &excb);
            expp[nume].a = exa;
            expp[nume].b = exb;
            expp[nume].r = exra;
            expp[nume++].c = exca;
            expp[nume].a = exb;
            expp[nume].b = exa;
            expp[nume].r = exrb;
            expp[nume++].c = excb;
        }
        if(bell()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
