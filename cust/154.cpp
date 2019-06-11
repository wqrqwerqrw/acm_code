// Author : Wqr_
// Time : 2019年06月10日 星期一 20时36分24秒

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int n;
const int nmax = 1e6 + 5;
set<P> mapp;
int bfs(){
    int ans = 0;
    while(!mapp.empty()){
        ans++;
        queue<P> q;
        auto it = mapp.begin();
        q.push(*it);
        mapp.erase(it);
        while(!q.empty()){
            P tmp = q.front();
            q.pop();
            int x = tmp.first;
            int y = tmp.second;
            for(int tx = -1; tx < 2; tx++){
                for(int ty = -1; ty < 2; ty++){
                    int nx = x + tx;
                    int ny = y + ty;
                    auto find = mapp.find(P(nx, ny));
                    if(find != mapp.end()){
                        q.push(*find);
                        mapp.erase(find);
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    iofuck;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        mapp.insert(P(a, b));
    }
    cout << bfs() << endl;
    return 0;
}
