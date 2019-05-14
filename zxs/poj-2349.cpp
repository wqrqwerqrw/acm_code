/*************************************************************************
    > File Name: poj-2349.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月11日 星期六 10时46分37秒
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
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> po; 
po ps[1010];
    double mapp[1010][1010];
int s, p;
double f(double in){ return in * in; }
double getdis(po a, po b){
    return sqrt(f(a.first - b.first) + f(a.second - b.second));
}
double mincost[510];
bool used[510];
void solve(){
    priority_queue<double> dis;
    for(int i = 0; i < p; i++){
        mincost[i] = INF;
        used[i] = 0;
    }
    mincost[0] = 0;
    int res = 0;
    while(true){
        int v = -1;
        for(int u = 0; u < p; u++){
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        res += mincost[v];
        dis.push(mincost[v]);
        for(int u = 0; u < p; u++){
            mincost[u] = min(mincost[u], mapp[v][u]);
        }
    }
    /*
    while(!dis.empty()){
        cout << dis.top() << " ";
        dis.pop();
    }
    */
    s--;
    while(s--){
        dis.pop();
    }
    printf("%0.2f\n", dis.top());
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s >> p;
        for(int i = 0; i < p; i++){
            scanf("%d %d", &ps[i].first, &ps[i].second);
        }
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
                if(i == j){
                    mapp[i][j] = 0;
                    continue;
                }
                mapp[i][j] = getdis(ps[i], ps[j]);
            }
        }
        solve();
    }
    return 0;
}
