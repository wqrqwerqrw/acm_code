/*************************************************************************
    > File Name: c.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月14日 星期二 23时15分14秒
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
#include<list>
#define MAXN 200100
using namespace std;
typedef long long ll;
int n;
int main(){
    string in;
    cin >> n;
    if(!n){
        cout << 0 << endl;
        return 0;
    }
    cin >> in;
    list<char> l;
    for(int i = 0; i < in.length(); i++){
        l.push_back(in[i]);
    }
    int w = 1;
    int ans = 0;
    for(auto it = l.begin(); it != l.end(); it++){
        if(w % 2){
            auto it2 = it;
            it2++;
            if(*it2 == *it){
                l.erase(it2);
                ans++;
                it--;
                w--;
            }
        }
        w++;
    }
    if(l.size() % 2) {
        ans++;
        l.pop_back();
    }
    cout << ans << endl;
    for(auto n : l){
        cout << n;
    }
    cout << endl;
    return 0;
}

