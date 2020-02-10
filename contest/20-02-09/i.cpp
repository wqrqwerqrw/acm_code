// Wqr_
// Time : 20/02/09
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct seg{
  int x1, x2, y1, y2;
};
struct point{
  int x, y;
};
signed main(){
#ifdef Wqr_
  freopen("in.txt","r",stdin);
#endif
  ios::sync_with_stdio(false),cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    vector<seg> ss(2); 
    vector<int> ps;
    for(int i = 0; i < 2; i++){
      cin >> ss[i].x1 >> ss[i].y1 >> ss[i].x2 >> ss[i].y2;
      ps.push_back(ss[i].x1);
      ps.push_back(ss[i].x2);
      ps.push_back(ss[i].y1);
      ps.push_back(ss[i].y2);
    }
    sort(ps.begin(), ps.end());
    int len = unique(ps.begin(), ps.end()) - ps.begin();
    ps.resize(len);
    // dbg(len, ps);
    auto getid = [&](int x){
      return (lower_bound(ps.begin(), ps.end(), x) - ps.begin()) * 2 + 1;
    };
    for(int i = 0; i < 2; i++){
      ss[i].x1 = getid(ss[i].x1);
      ss[i].x2 = getid(ss[i].x2);
      ss[i].y1 = getid(ss[i].y1);
      ss[i].y2 = getid(ss[i].y2);
    }
    const int N = 20;
    vector<vector<int>> vis(N, vector<int>(N, 0));
    for(int i = 0; i < 2; i++){
      int x1 = ss[i].x1, x2 = ss[i].x2;
      int y1 = ss[i].y1, y2 = ss[i].y2;
      for(int x = x1; x <= x2; x++) vis[x][y1] = vis[x][y2] = 1;
      for(int y = y1; y <= y2; y++) vis[x1][y] = vis[x2][y] = 1;
    }
    int ans = 0;
    vector<int> mx = {0, 0, -1, 1};
    vector<int> my = {1, -1, 0, 0};
    function<void(int, int)> dfs = [&](int x, int y){
      vis[x][y] = 1;
      for(int i = 0; i < 4; i++){
        int xx = x + mx[i];
        int yy = y + my[i];
        if(xx < 0 || yy < 0 || xx >= N || yy >= N || vis[xx][yy]) continue;
        dfs(xx, yy);
      }
    };
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(!vis[i][j]) {
          dfs(i, j);
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}