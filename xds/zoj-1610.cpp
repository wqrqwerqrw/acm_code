/*************************************************************************
    > File Name: zoj-1610.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月29日 星期三 20时34分07秒
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
const int nmax = 8000 + 5;
int n;
int cnt;
int lz[nmax << 2], book[nmax], color[nmax];
void pushdown(int rt){
    if(lz[rt]){
        lz[rt << 1] = lz[rt << 1 | 1] = lz[rt];
        lz[rt] = 0;
    }
}
void update(int L, int R, int C, int l, int r, int rt){
    if(l > R || r < L) return ;
    if(L <= l && r <= R){
        lz[rt] = C;
        return ;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    update(L, R, C, l, mid, rt << 1);
    update(L, R, C, mid + 1, r, rt << 1 | 1);
}
void he(int l, int r, int rt){
    if(l == r){
        color[cnt++] = lz[rt];
        return ;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    he(l, mid, rt << 1);
    he(mid + 1, r, rt << 1 | 1);
}
int main(){
    while(cin >> n){
        cnt = 0;
        memset(lz, 0, sizeof(lz));
        memset(book, 0, sizeof(book));
        int a, b, c;

        while(n--){
            scanf("%d %d %d", &a, &b, &c);
            update(a + 1, b, c + 1, 1, 8000, 1);
        }
        he(1, 8000, 1);
        for(int i = 0; i < cnt;){
            int j = i + 1;
            book[color[i]]++;
            while(color[j] == color[i] && j < cnt) j++;
            i = j;
        }
        for(int i = 1; i <= 8000 + 1; i++){
            if(book[i])
                printf("%d %d\n", i - 1, book[i]);
        }
        printf("\n");
    }
    return 0;
}
