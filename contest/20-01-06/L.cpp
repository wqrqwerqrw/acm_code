/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 20/01/06
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> P;
const int nmax = 100000+10;
const int mmax = 1000000 + 10;
P ans[nmax];
int n, m;
struct node{
    int b, dx, dy;
};
vector<node> G[nmax];
/*
void bfs(){
    queue<int> q;
    q.push(0);
    unordered_set<int> sett;
    int maxx = 0, minx = 0, maxy = 0, miny = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(sett.find(a) != sett.end()){
            continue;
        }
        sett.insert(a);
        vector<node> cur = G[a];
        for(node i : cur){
            q.push(i.b);
            ans[i.b].first = ans[a].first + i.dx;
            ans[i.b].second = ans[a].second + i.dy;
            int x = ans[i.b].first;
            int y = ans[i.b].second;
            maxx = max(maxx, x);
            minx = min(miny, x);
            maxy = max(maxy, y);
            miny = min(miny, y);
        }
    }
    int mvx = 0;
    int mvy = 0;
    if(maxx >= 1e9) mvx = 1e9 - maxx - 1;
    if(minx <= -1e9) mvx = -1e9 - minx + 1;
    if(maxy >= 1e9) mvy = 1e9 - maxy - 1;
    if(miny <= -1e9) mvy = -1e9 - miny + 1;
    for(int i = 0; i < n; i++){
        cout << ans[i].first + mvx << " " << ans[i].second + mvy << endl;
    }
}
*/
bool book[nmax];
int maxx = 0, minx = 0, maxy = 0, miny = 0;
void dfs(int cur){
    if(book[cur]) return ;
    book[cur] = 1;
    for(auto i : G[cur]){
        ans[i.b].first = ans[cur].first + i.dx;
        ans[i.b].second = ans[cur].second + i.dy;
        int x = ans[i.b].first;
        int y = ans[i.b].second;
        maxx = max(maxx, x);
        minx = min(miny, x);
        maxy = max(maxy, y);
        miny = min(miny, y);
        dfs(i.b);
    }
}
int32_t main(){
#ifdef Wqr_
    freopen("in.txt","r",stdin);
#endif
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    int aa, bb, xx, yy;
    for(int i = 0; i < m; i++){
        cin >> aa >> bb >> xx >> yy;
        aa--;
        bb--;
        G[aa].push_back({bb, xx, yy});
        G[bb].push_back({aa, -xx, -yy});
    }
    ans[0] = {0, 0};
    //bfs();
    dfs(0);
    int mvx = 0;
    int mvy = 0;
    if(maxx >= 1e9) mvx = 1e9 - maxx - 1;
    if(minx <= -1e9) mvx = -1e9 - minx + 1;
    if(maxy >= 1e9) mvy = 1e9 - maxy - 1;
    if(miny <= -1e9) mvy = -1e9 - miny + 1;
    for(int i = 0; i < n; i++){
        cout << ans[i].first + mvx << " " << ans[i].second + mvy << endl;
    }

    return 0;
}