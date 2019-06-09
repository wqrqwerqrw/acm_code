/*************************************************************************
    > File Name: b.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月05日 星期三 22时49分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#define iofuck std::ios::sync_with_stdio(false)
using namespace std;
typedef unsigned long long ll;
ll l;
ll bian = 4294967295;
ll ans = 0;
ll tmp = 0;
ll fornum = 0;
stack<ll> loop;
stack<ll> addd;
int main(){
    iofuck;
    cin >> l;
    string in;
    addd.push(0);
    while(l--){
        cin >> in;
        if(in[0] == 'a'){
            addd.top()++;
        }else if(in[0] == 'f'){
            addd.push(0);
            ll loopnum;
            cin >> loopnum;
            loop.push(loopnum);
            fornum++;
        }else if(in[0] == 'e'){
            fornum--;
            ll tmpp = addd.top() * loop.top();
            if(tmpp / loop.top() != addd.top() || tmpp > bian){
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            loop.pop();
            addd.pop();
            addd.top() += tmpp;
        }
    }
    if(!addd.empty()){
        ans += addd.top();
    }
    if(ans <= bian)
        cout << ans << endl;
    else {
        cout << "OVERFLOW!!!" << endl;
        return 0;
    }
    return 0;
}
