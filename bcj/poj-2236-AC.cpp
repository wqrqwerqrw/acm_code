/**********************************************************
    > File Name : poj-2236.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 21 16:14:05
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
typedef pair<int, int> p;
int n, d;
p com[1010];
double map[1010][1010];
int par[1010];
int high[1010];
vector<int> paired;
void init(int a){
    for(int i = 0; i < n; i++){
        par[i] = i;
        high[i] = 0;
    }
}

int find(int a){
    if(par[a] == a) return a;
    else return par[a] = find(par[a]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return ;
    if(high[a] > high[b]){
        par[b] = a;
    }else if(high[a] < high[b]){
        par[a] = b;
    }else{
        par[a] = b;
        high[b]++;
    }
}

bool same(int a, int b){
    return find(a) == find(b);
}
void getdis(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                map[i][j] = 0;
                continue;
            }
            map[i][j] = sqrt(pow(double(com[i].first - com[j].first), 2) + pow(double(com[i].second - com[j].second), 2));
        }
    }
}
int main(){
    cin >> n >> d;
    int ina, inb;
    for(int i = 0; i < n; i++){
        cin >> com[i].first >> com[i].second;
    }
    getdis();
    init(n);
    char in;
    while(cin >> in){
        int p, q;
        if(in == 'O'){
            scanf("%d", &p);
            p--;
            paired.push_back(p);
            for(int i = 0; i < paired.size() - 1; i++){
                if(map[paired[i]][p] <= d){
                    uni(paired[i], p);
                }
            }
        }else{
            scanf("%d %d", &p, &q);
            p--;
            q--;
            if(same(p, q)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
    
}