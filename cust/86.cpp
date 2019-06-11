// Author : Wqr_
// Time : 2019年06月10日 星期一 21时06分40秒

#include<bits/stdc++.h>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map<int, int> men;
bool ifmen[100000 + 5];
bool book[200000 + 5];
struct node{
    int now, men, time;
};
bool cmp(node &a, node &b){
    return a.men > b.men;
}
vector<node> ans;
int n, m, k;
void bfs(){
    queue<node> q;
    node start;
    q.push(node{0, 0, 0});
    book[0] = 1;
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        if(tmp.time > k) continue;
        if(tmp.now > 2 * n) continue;
        if(tmp.now == n) ans.push_back(tmp);
        if(ifmen[tmp.now]){
            if(!book[men[tmp.now]]){

            }
        }
        for(int i = -1; i <= 1; i++){
            if(i == 0) continue;
            int nx = tmp.now + i;
            if(nx < 0) continue;
            if(ifmen[nx]){
                if(!book[men[nx]]){
                    cout << men[nx] << endl;
                    q.push(node{men[nx], tmp.men + 1, tmp.time + 1});
                    book[men[nx]] = 1;
                }
            }
            if(!book[nx]){
                q.push(node{tmp.now + nx, tmp.men, tmp.time + 1});
                book[nx] = 1;
            }
        }
    }
    if(ans.size()){
        sort(ans.begin(), ans.end(), cmp);
        for(auto tmp : ans){
            cout << tmp.men << " " << tmp.time << " " << tmp.now << endl;
        }
        cout << ans[0].men << " " << ans[0].time << endl;
    }else{
        cout << "summon TanYz" << endl;
    }
}
int main(){
    iofuck;
    while(cin >> n >> m >> k){
        memset(ifmen, 0, sizeof(ifmen));
        memset(book, 0, sizeof(book));
        men.clear();
        ans.clear();
        int a, b;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            men[a] = b;
            men[b] = a;
            ifmen[a] = 1;
            ifmen[b] = 1;
        }
        bfs();
    }
    return 0;
}
