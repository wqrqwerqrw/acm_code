/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月10日 星期三 16时52分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    /*
    if(k == 1){
        printf("%d\n", n + n * (n - 1)/2 * n);
        int a = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j) printf(" ");
                printf("%d", a++);
            }
            printf("\n");
        }
    }else{
    */
    int small = 1;
    int big = n * (k - 1) + 1;
    printf("%d\n", n * big + n * (n - 1) / 2 * (n - k + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j != 1) printf(" ");
            if(j < k) printf("%d", small++);
            else printf("%d", big++);
        }
        printf("\n");
    }
    return 0;
}
