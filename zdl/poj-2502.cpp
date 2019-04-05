/*************************************************************************
    > File Name: poj-2502.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月02日 星期二 20时32分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int Nmax = 1010;
const int Mmax = 150100;
struct node{
    int next, to, w;
}eg[Mmax];
struct point{
    int x, y;
}start, end, ps[1010];
vector<point> ls[1010];
int d[Mmax], head[Mmax];
void add(int u, int v, int w){
    eg[cnt].w = w;
    eg[cnt].to = v;
    eg[cnt].next = head[u];
    head[u] = cnt++;
}
double getv(point a, point b, int type){
    double dis = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    // walk
    if(type == 1){
        return dis / 10 * (double(50) / 3);
    }else{
        return dis / 40 * (double(50) / 3);
    }
}
int main(){
    scanf("%d %d", &start.x, &start.y);
    scanf("%d %d", &end.x, &end.y);
    
    return 0;
}
