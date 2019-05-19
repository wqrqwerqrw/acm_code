/*************************************************************************
    > File Name: 3.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月19日 星期日 14时58分05秒
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
char mapp[110][110];
int c(int a, int b){
    int ans = 0;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(a + i < 0 || a + i >= n || b + j < 0 || b + j >= m) continue;
            if(mapp[a + i][b + j] == '*') ans++;
        }
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mapp[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mapp[i][j] == '*') cout << "*";
            else cout << c(i, j);
        }
        cout << endl;
    }
    return 0;
}
