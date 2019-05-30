/*************************************************************************
    > File Name: 1029a.cpp
    > Author: Wqr_
    > Mail: xueduanwei@126.com 
    > Created Time: 2019年05月29日 星期三 20时59分55秒
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
int n, k;
vector<int> per(string &p) {
    int n = p.size();
    vector<int> q(n + 1);
    q[1] = 0;
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && p[i] != p[k]) k = q[k];
        if (p[i] == p[k]) k++;
        q[i + 1] = k;
    }
    return q;
}
int main(){
    string in;
    cin >> n >> k;
    cin >> in;
    vector<int> next = per(in);
    int num = next.back();
    cout << in;
    string out = in.substr(num);
    for(int i = 1; i < k; i++){
        cout << out;
    }
    cout << endl;
    return 0;
}
