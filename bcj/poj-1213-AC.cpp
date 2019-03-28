/**********************************************************
    > File Name : poj-1213.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 21 19:17:41
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
int n, m;
int per[1010];
int high[1010];
bool book[1010];
void init(int a){
    for(int i = 0; i < a; i++){
        per[i] = i;
        high[i] = 0;
    }
}

int find(int a){
    if(per[a] == a) return a;
    else return per[a] = find(per[a]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(high[a] > high[b]){
        per[b] = a;
    }else if(high[a] < high[b]){
        per[a] = b;
    }else{
        per[a] = b;
        high[b]++;
    }
}
bool same(int a, int b){
    return find(a) == find(b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(book, 0, sizeof(book));
        int ans = 0;
        cin >> n >> m;
        init(n);
        int a, b;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            uni(a - 1, b - 1);
        }
        for(int i = 0; i < n; i++){
            if(per[i] == i) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}