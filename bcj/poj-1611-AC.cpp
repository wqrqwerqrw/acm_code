/**********************************************************
    > File Name : poj-1611.cpp
    > Author : Wqr_
    > Mail : xueduanwei@126.com
    > Created Time : 19 03 21 18:48:50
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
int per[30010];
int high[30030];
int toin[30010];
bool book[30010];
int n, m;
int k;
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
    if(a == b) return ;
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
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        init(n);
        int ans = 1;
        memset(book, 0, sizeof(book));
        for (int j = 0; j < m; j++) {
            scanf("%d", &k);
            for (int i = 0; i < k; i++) {
                scanf("%d", toin + i);
                book[toin[i]] = 1;
            }
            for (int i = 1; i < k; i++) {
                uni(toin[i], toin[i - 1]);
            }
        }
        for (int i = 1; i < n; i++) {
            if (book[i] && same(0, i)) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}