/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月03日 星期一 22时41分12秒
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
int n;
const int nmax = 1e5 + 5;
bool mark[nmax];
vector<int> per;
void prime()
{
    for(int i = 2; i < nmax; i++){
        if(mark[i]) continue;
        per.push_back(i);
        for(int j = 2; j * i < nmax; j++){
            mark[j * i] = 1;
        }
    }
}
int main(){
    prime();
    cin >> n;
    int ans[nmax];
    int flag = 1;
    for(auto tmp : per){
        for(int i = 1; i * tmp < nmax; i++){
            ans[i * tmp] = flag;
        }
        flag++;
    }
    for(int i = 2; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
