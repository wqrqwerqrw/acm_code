// Author : Wqr_
// Time : 19/09/24
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ttt cout << "<><><>" << endl;
using namespace std;
typedef long long ll;
vector<int> v;
vector<bool> vis(70, 0);
vector<int> to(70);
int n, sum;
void dfs(int length, int num, int goal, int now){
    if(num * goal == sum) {
        cout << goal << endl;
        exit(0);
    }
    if(length == goal){
        dfs(0, num + 1, goal, 0);
        return ;
    }
    if(goal - length < *v.rbegin()) return ;
    //auto i = lower_bound(v.begin(), v.end(), goal - length) - v.begin();
    for(int i = now; i < n; i++){
        if(!vis[i] && length + v[i] <= goal){
            vis[i] = 1;
            dfs(length + v[i], num, goal, i + 1);
            vis[i] = 0;
            if(length + v[i] == goal || length == 0) return;
            i = to[i];
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    int in;
    for(int i = 0; i < n; i++){
        cin >> in;
        if(in <= 50)
            v.push_back(in);
    }
    n = v.size();
    sort(v.begin(), v.end(), greater<int>());
    for(auto i : v) sum += i;
    for(int i = 0; i < n - 1; i++){
        int tmp = i;
        while(v[tmp] == v[tmp+1]) tmp++;
        to[i] = tmp;
    }
    to[n-1] = n-1;
    for(int i = v[0]; i <= sum / 2; i++){
        if(sum % i == 0) dfs(0, 0, i, 0);
    }
    cout << sum << endl;
    return 0;
}