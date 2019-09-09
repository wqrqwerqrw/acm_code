/*************************************************************************
    > File Name: a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年04月29日 星期一 18时41分14秒
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
int n;
int mapp[30][30];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mapp[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n / 2; i++){
        int a = (1<<i) - 1;
        while(a < 1 << n){
            int b = ~a;
            int tmp = 0;
            for(int j = 0; j < n; j++){
                if(a>>j&1){
                    for(int k = 0; k < n; k++){
                        if(b>>k&1){
                            tmp += mapp[j][k];
                        }
                    }
                }
                if(tmp > ans) ans = tmp;
            }
            int x = a & -a, y = a + x;
            a = ((a & ~y) / x >> 1) | y;
        }
    }
    cout << ans << endl;
    return 0;
}
