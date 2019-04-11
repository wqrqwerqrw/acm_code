/*************************************************************************
    > File Name: h.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月11日 星期四 21时04分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int book[2010];
int main(){
    int maxn = 0;
    int in, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &in);
        book[in]++;
        if(book[in] > maxn) maxn = book[in];
    }
    cout << n - maxn;
    return 0;
}
