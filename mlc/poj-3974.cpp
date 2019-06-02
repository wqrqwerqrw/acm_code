/*************************************************************************
    > File Name: poj-3974.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年06月01日 星期六 12时23分05秒
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
const int nmax = 1000000 + 5;
char Ma[nmax << 1];
int Mp[nmax << 1];
int mlc(string in){
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i = 0; i < in.length(); i++){
        Ma[l++] = in[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i = 0; i < l; i++){
        Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
        while(Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
        if(i + Mp[i] > mx){
            mx = i + Mp[i];
            id = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < 2 * in.length() + 2; i++){
        ans = max(ans, Mp[i] - 1);
    }
    return ans;
}
int main(){
    iofuck;
    string in;
    int kase = 0;
    while(cin >> in){
        if(in[0] == 'E' && in[1] == 'N' && in[2] == 'D' && in.length() == 3)
            break;
        cout << "Case " << ++kase << ": ";
        cout << mlc(in) << endl;
    }
    return 0;
}
