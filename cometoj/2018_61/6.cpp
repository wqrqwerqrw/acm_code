/*************************************************************************
    > File Name: 6.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 21时08分22秒
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
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
int n, m, q;
const int nmax = 1000 + 5;
bool mapp[nmax][nmax];
int pa(int x, int y){
    int book;
    int ret = 0;
    book = 0;
    for(int i = x - 1; i <= x; i++){
        for(int j = y - 1; j <= y; j++){
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            book += mapp[i][j];
        }
    }
    if(book == 4) ret++;
    book = 0;
    for(int i = x - 1; i <= x; i++){
        for(int j = y; j <= y + 1; j++){
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            book += mapp[i][j];
        }
    }
    if(book == 4) ret++;
    book = 0;
    for(int i = x; i <= x + 1; i++){
        for(int j = y - 1; j <= y; j++){
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            book += mapp[i][j];
        }
    }
    if(book == 4) ret++;
    book = 0;
    for(int i = x; i <= x + 1; i++){
        for(int j = y; j <= y + 1; j++){
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            book += mapp[i][j];
        }
    }
    if(book == 4) ret++;
    return ret;

}
int main(){
    iofuck;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mapp[i][j] = 1;
        }
    }
    int x, y;
    int ans = (n - 1) * (m - 1);
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        x--, y--;
        ans -= pa(x, y);
        mapp[x][y] = 0;
        cout << ans << endl;
    }
    return 0;
}
