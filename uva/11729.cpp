/*************************************************************************
    > File Name: 11729.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月25日 星期六 19时38分24秒
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
int n;
struct job{
    int j, b;
    bool operator < (const job& x) const {
        return j > x.j;
    }
};
int main(){
    int kase = 0;
    while(cin >> n){
        if(n == 0) break;
        int b, j;
        vector<job> v;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &b, &j);
            v.push_back(job{j, b});
        }
        sort(v.begin(), v.end());
        int s = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            s += v[i].b;
            ans = max(ans, s + v[i].j);
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
