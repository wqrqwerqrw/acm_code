#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
using namespace std;
int main(){
    int n, q, t;
    string name;
    queue<pair<string, int>> Q;

    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps = 0, a;

    while(!Q.empty()){
        u = Q.fount(); Q.pop();
        a = min(u.second, q);
        u.second -= a;
        elaps += a;
        if(u.second > 0){
            Q.push(u);
            cout << u.first << " " << elaps << endl;
        }
    }
    return 0;
}
