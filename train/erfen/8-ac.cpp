/*************************************************************************
    > File Name: 8.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月25日 星期四 09时28分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int a[505], b[505], c[505];
int t[505 * 505];
int l, n, m, s;
int num = 0;
bool solve(int x){
    for(int i = 0; i < m; i++){
        if(binary_search(t, t + num, (x - c[i]))) return 1;
    }
    return 0;
}
int main(){
    int kase = 0;
    while(cin >> l >> n >> m){
        num = 0;
        printf("Case %d:\n", ++kase);
        for(int i = 0; i < l; i++){
            scanf("%d", a + i);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", b + i);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", c + i);
        }
        for(int i = 0; i < l; i++){
            for(int j = 0; j < n; j++){
                t[num] = a[i] + b[j];
                ++num;
            }
        }
        sort(t, t + num);
        int s;
        scanf("%d", &s);
        while(s--){
            long long x;
            scanf("%d", &x);
            if(solve(x)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
