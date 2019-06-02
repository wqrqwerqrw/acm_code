/*************************************************************************
    > File Name: 4.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 19时13分11秒
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
int book[20];
int main(){
    iofuck;
    int in;
    for(int i = 0; i < 18; i++){
        cin >> in;
        book[in]++;
    }
    int ans = 0;
    for(int i = 1; i <= 13; i++){
        ans += book[i] % 2;
    }
    cout << ans + book[0] << endl;
    return 0;
}
