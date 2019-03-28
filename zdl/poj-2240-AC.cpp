/**********************************************************
    > File Name : poj-2240.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 24 21:10:22
**********************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
#define INF 1<<28
using namespace std;
struct edge{
    int f, t;
    double c;
}edge[10010];
int eee;
map<string, int> mapp;
int n, m;
double dis[10010];
bool bell(){
    memset(dis, 0, sizeof(dis));
    dis[0] = 10000;
    for(int i = 0; i < n - 1; i++){
        bool flag = false;
        for(int j = 0; j < eee; j++){
            if(dis[edge[j].t] < dis[edge[j].f] * edge[j].c){
                dis[edge[j].t] = dis[edge[j].f] * edge[j].c;
                flag = true;
            }
        }
        if(!flag) break;
    }
    for (int j = 0; j < eee; j++) {
        if (dis[edge[j].t] < dis[edge[j].f] * edge[j].c) {
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    int kase = 0;
    while(cin >> n){
        if(n == 0) break;
        eee = 0;
        string in;
        for(int i = 0; i < n; i++){
            cin >> in;
            mapp[in] = i;
        }
        cin >> m;
        string a, b;
        double lv;
        for(int j = 0; j < m; j++){
            cin >> a >> lv >> b;
            edge[eee].f = mapp[a];
            edge[eee].t = mapp[b];
            edge[eee++].c = lv;
        }
        cout << "Case " << ++kase << ": ";
        if(bell()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
