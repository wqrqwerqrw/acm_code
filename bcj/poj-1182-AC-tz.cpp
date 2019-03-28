/**********************************************************
    > File Name : poj-2236.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 20 21:09:04
**********************************************************/
// 329ms
#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int par[150010];
int high[150010];
int D[100010];
int X[100010];
int Y[100010];

int n, k;
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        high[i] = 0;
    }
}

int find(int a){
    if(par[a] == a) return a;
    else{
         return par[a] = find(par[a]);
    }
}

void unite(int a, int b){
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

void solve(){
    init(n * 3);
    int ans = 0;
    for(int j = 0; j < k; j++){
        int d = D[j];
        int x = X[j] - 1;
        int y = Y[j] - 1;
        if(x < 0 || x >= n || y < 0 || y >= n){
            ans++;
            continue;
        }

        if(d == 1){
            if(same(x, y + n) || same(x, y + 2 * n)){
                ans++;
            }else{
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        }

        if(d == 2){
            if(same(x, y) || same(x, y + 2 * n)){
                ans++;
            }else{
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    cout << ans << endl;
}

int main(){
    cin >> n >> k;
    int din, xin, yin;
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", D + i, X + i, Y + i);
    }
    solve();
    return 0;
}