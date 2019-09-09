/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月06日 星期一 19时40分20秒
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
typedef pair<string, int> pa;
int fen[20];
bool cmp(const pa &a, const pa &b){
    if(a.second != b.second)
        return a.second > b.second;
    else{
        return a.first.compare(b.first) < 0 ? 1 : 0;
    }
}
int main(){
    int n, m, g;
    while(scanf("%d", &n) && n){
        scanf("%d %d", &m, &g);
        int ans = 0;
        map<string, int> jifen;
        for(int i = 0; i < m; i++){
            scanf("%d", fen + i + 1);
        }
        for(int i = 0; i < n; i++){
            string hao;
            int num;
            cin >> hao >> num;
            jifen[hao] = 0;
            for(int j = 0; j < num; j++){
                int in;
                scanf("%d", &in);
                jifen[hao] += fen[in];
            }
            if(jifen[hao] >= g){
                ans++;
            }
        }
        cout << ans << endl;
        vector<pa> vec(jifen.begin(), jifen.end());
        sort(vec.begin(), vec.end(), cmp);
        for(pa vecc : vec){
            if(vecc.second >= g)
            cout << vecc.first << " " << vecc.second << endl;
        }
    }
    return 0;
}
