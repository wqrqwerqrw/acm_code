/*************************************************************************
    > File Name: r.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月09日 星期四 09时03分55秒
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
typedef long long ll;
typedef pair<int, int> pa;
pa node[110];
int n;
bool cmp(pa a, pa b){
    return a.second < b.second;
}
int main(){
    while(cin >> n){
        if(!n) break;
        for(int i = 0; i < n; i++){
            cin >> node[i].first >> node[i].second;
        }
        sort(node, node + n, cmp);
        int ans = 1;
        int end = node[0].second;
        for(int i = 1; i < n; i++){
            if(node[i].first >= end){
                end = node[i].second;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
