/*************************************************************************
    > File Name: p.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月10日 星期五 10时23分37秒
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
int n, m;
int num[1010];
int main(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            num[i] = i + 1;
        }
        m--;
        while(m--){
            next_permutation(num, num + n);
        }
        for(int i = 0; i < n; i++){
            if(i) printf(" ");
            printf("%d", num[i]);
        }
        cout << endl;
    }
    return 0;
}
